#import "NSBundle_dyld.h"
#import <limits.h>
#import <Foundation/NSString.h>
#import <Foundation/NSProcessInfo.h>
#import <Foundation/NSAutoreleasePool.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <algorithm>
#include <map>
#include "../util/log.h"

extern char g_darwin_executable_path[PATH_MAX];
extern int g_argc asm("NXArgc");
extern char** g_argv asm("NXArgv");
static NSBundle* _mainBundle = 0;
static NSAutoreleasePool* g_pool = 0;

void MethodSwizzle(Class aClass, SEL orig_sel, SEL alt_sel);

id GetBundle(const char* filename)
{
	NSString *filepath = [[NSString alloc] initWithCString:filename];
	filepath = [filepath stringByDeletingLastPathComponent];
	LOG << "Getting bundle for path " << [filepath UTF8String] << std::endl;
	NSBundle *bundle = [[NSBundle alloc] initWithPath: filepath];
	LOG << "Bundle is " << bundle << std::endl;
	return bundle;
}

std::map<Class, NSBundle*> g_bundleMap;

void BundleAddClass(id bundle, Class cls)
{
	NSBundle *b = (NSBundle*)bundle;
	[b addClass: cls];
	g_bundleMap[cls] = bundle;
}

static void myinit()
{
	LOG << "Swizzling methods in NSBundle\n";
	
	MethodSwizzle(objc_getMetaClass("NSBundle"), @selector(mainBundle), @selector(x_mainBundle));
	MethodSwizzle(objc_getMetaClass("NSBundle"), @selector(bundleForClass:), @selector(x_bundleForClass:));
	
	// Many OS X apps assume that there is a "default" autorelease pool provided
	g_pool = [[NSAutoreleasePool alloc] init];
	
	GSInitializeProcess(g_argc, g_argv, environ);
	
	/*
	const char* last = strrchr(g_darwin_executable_path, '/');
	if (last != 0)
	{
		last++;
		
		NSString* str = [NSString stringWithUTF8String:last];
		[[NSProcessInfo processInfo] setProcessName:str];
	}
	*/
}

__attribute__((destructor)) static void myexit()
{
	[g_pool drain];
	g_pool = 0;
}

@implementation NSBundle (NSBundle_dyld)

+(void) load
{
	myinit();
#if 0
	LOG << "Swizzling methods in NSBundle\n";
	RenameSelector([self class], @selector(mainBundle), @selector(gnu_mainBundle));
	RenameSelector([self class], @selector(x_mainBundle), @selector(mainBundle));
#endif
}

+(NSBundle*) x_mainBundle
{
	LOG << "x_mainBundle() called\n";
	if (!_mainBundle)
	{
		std::string path = g_darwin_executable_path;
		size_t pos;

		//size_t pos = path.find_last_of('/');
		//if (pos == std::string::npos)
		//	return nil;

		//path.resize(pos+1);
		//path += "Resources";
		
		if ((pos = path.rfind("Contents/")) != std::string::npos)
		{
			path.resize(pos+8);
		}
		else if ((pos = path.rfind(".app/")) != std::string::npos)
		{
			// "path.endsWith()"
			// if (path.compare(path.size()-7, 7, "/MacOS/") == 0)
			// 	path.resize(path.size() - 7);
			path.resize(pos+4);
		}

		LOG << "NSBundle::x_mainBundle(): deduced " << path << " as resource path\n";

		_mainBundle = [self alloc];
		_mainBundle = [_mainBundle initWithPath:[NSString stringWithUTF8String:path.c_str()]];
	}

	return _mainBundle;
}

+(NSBundle*) x_bundleForClass: (Class) aClass
{
	NSBundle *bundle = nullptr;

	auto i = g_bundleMap.find(aClass);
	if (i != g_bundleMap.end())
	{
		bundle = i->second;
	}
	else
	{
		bundle = [super gnu_bundleForClass:aClass];
	}
	return bundle;
}

-(void) addClass : (Class) cls
{
	NSValue *value = [NSValue valueWithPointer: (void*)cls];
	[self->_bundleClasses addObject: value];
}

@end

struct objc_method
{
	SEL selector;
	const char* types;
	IMP imp;
};

void MethodSwizzle(Class aClass, SEL orig_sel, SEL alt_sel)
{
	Method orig_method, alt_method;
   
	orig_method = (Method) class_getInstanceMethod(aClass, orig_sel);
	alt_method = (Method) class_getInstanceMethod(aClass, alt_sel);
   
	if (orig_method && alt_method)
	{
		std::swap(orig_method->types, alt_method->types);
		std::swap(orig_method->imp, alt_method->imp);
	}
	else
	{
		LOG << "Swizzling method failed\n";
	}
}


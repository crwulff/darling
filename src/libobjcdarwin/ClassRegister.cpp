#include "ClassRegister.h"
#include <libdyld/dyld_public.h>
#include <util/debug.h>

#ifndef OBJC_ABI_2
#	include "old/protocol.h"
#	include "old/class.h"
#	include "old/category.h"
#else
#	include "new/protocol.h"
#	include "new/class.h"
#	include "new/category.h"
#endif
#include "common/selector.h"
#include <map>
#include <queue>
#include <vector>
#include <cassert>
#include "NSDarwinFramework.h"

// Superclass references in Mach-O don't use classref
// Neither do category class references
std::map<const void*,Class> & getClassPointers(void) {
	static std::map<const void*,Class> g_classPointers;
	return g_classPointers;
}

std::queue<std::pair<Class,IMP>> & getPendingInitClasses(void) {
	static std::queue<std::pair<Class,IMP>> g_pendingInitClasses;
	return g_pendingInitClasses;
}

extern id GetBundle(const char* filename);

void RegisterNativeClass(void* cls)
{
	LOG << "Register Native Class @ " << cls << std::endl;

	class_getSuperclass(reinterpret_cast<Class>(cls)); // HACK to force the class to be resolved
	getClassPointers()[cls] = reinterpret_cast<Class>(cls);
}

static void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace)
{
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos)
	{
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

// Here we process Mach-O files that have been loaded before this native library
// Then we register a handler to process all images loaded in the future
__attribute__((constructor))
	void RegisterAlreadyLoadedClasses()
{
	for (uint32_t i = 0; i < _dyld_image_count(); i++)
	{
		ProcessImageLoad(i);
	}

	_dyld_register_func_for_add_image(ProcessImageLoad);
	_dyld_register_func_for_remove_image(ProcessImageUnload);
	_dyld_register_func_for_add_objc_class(RegisterNativeClass);

	//std::cout << "Done registering\n";
}

void ProcessImageLoad(uint32_t image_index)
{
	// Mark off images as we process them. This can be called twice for the same image
	// if the image was already added prior to RegisterAlreadyLoadedClasses being called.
	static std::vector<bool> loadedImages;
	if (loadedImages.size() <= image_index) loadedImages.resize(image_index+1, false);
	if (loadedImages[image_index]) return;
	loadedImages[image_index] = true;

	const struct mach_header *mh = _dyld_get_image_header(image_index);
	intptr_t slide = _dyld_get_image_vmaddr_slide(image_index);
	const char *name = _dyld_get_image_name(image_index);
	unsigned long size;
	std::vector<const char*> classNames;
	void* dataPtr = nullptr;

	LOG << "ObjC ProcessImageLoad @" << mh << std::endl;

#ifdef OBJC_ABI_2
	ProcessProtocolsNew(mh, slide);

	classNames = ProcessClassesNew(mh, slide, SEG_OBJC_CLASSLIST_NEW, SECT_OBJC_CLASSLIST_NEW, image_index);
	dataPtr = getsectdata(mh, SEG_OBJC_CLASSLIST_NEW, SECT_OBJC_CLASSLIST_NEW, &size);
	ProcessClassesNew(mh, slide, SEG_OBJC_CLASSREFS_NEW, SECT_OBJC_CLASSREFS_NEW, image_index);
	ProcessClassesNew(mh, slide, SEG_OBJC_SUPERREFS_NEW, SECT_OBJC_SUPERREFS_NEW, image_index);

	ProcessCategoriesNew(mh, slide, image_index);
#else
	module_info* modinfo;
	ProcessProtocolsOld(mh, slide);

	modinfo = reinterpret_cast<module_info*>(
		getsectdata(mh, SEG_OBJC_MODINFO_OLD, SECT_OBJC_MODINFO_OLD, &size)
	);

	if (modinfo && modinfo->symtab)
	{
		classNames = ProcessClassesOld(mh, slide, modinfo);
		dataPtr = modinfo;
		ProcessCategoriesOld(mh, slide, modinfo);
	}
#endif

	UpdateSelectors(mh, slide);

	// Do this only for dynamic libs (slide > 0)
	if (!classNames.empty() && slide > 0)
	{
		// Generate a NSFramework_XXXX class for GNUstep's NSBundle
		RegisterFramework(&classNames[0], classNames.size(), name);
	}

	static SEL selInit = sel_getUid("load");
	auto & g_pendingInitClasses = getPendingInitClasses();
	while (!g_pendingInitClasses.empty())
	{
		auto pair = g_pendingInitClasses.front();
		g_pendingInitClasses.pop();
		pair.second(reinterpret_cast<objc_object*>(pair.first), selInit);
	}

	_dyld_finalize_symbols(image_index);
	LOG << "ObjC ProcessImageLoad done @" << mh << std::endl;
}

void ProcessImageUnload(uint32_t image_index)
{
	// TODO
}


#ifndef NSBUNDLE_DYLD_H
#define NSBUNDLE_DYLD_H
#include <Foundation/NSBundle.h>

@interface NSBundle (NSBundle_dyld)

+(NSBundle*) x_mainBundle;

+(NSBundle*) x_bundleForClass: (Class) aClass;

-(void) addClass : (Class) cls;

-(NSString*) x_executablePath;

-(BOOL) x_load;

@end


#endif


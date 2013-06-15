
#ifndef _AnimationManager_H_
#define _AnimationManager_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>

@class CAMediaTimingFunction;

@interface NSAnimationManager : NSObject {
}

+ (NSAnimationManager*) currentAnimationManager;

@end

#endif

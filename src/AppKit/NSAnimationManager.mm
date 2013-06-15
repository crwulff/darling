
#import "NSAnimationManager.h"

#import <Foundation/NSThread.h>

@implementation NSAnimationManager

+ (NSAnimationManager*) currentAnimationManager
{
  NSMutableDictionary *threadDict = [[NSThread currentThread] threadDictionary];
  NSAnimationManager *animationManager = [threadDict objectForKey: @"animationManager"];

  if (animationManager == nil)
    {
      animationManager = [[NSAnimationManager alloc] init];
      [threadDict setObject: animationManager forKey: @"animationManager"];
    }

  return animationManager;
}

@end


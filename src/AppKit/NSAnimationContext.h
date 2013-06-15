
#ifndef _AnimationContext_H_
#define _AnimationContext_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSArray.h>

@class CAMediaTimingFunction;

@interface NSAnimationContext : NSObject {
  @private
    NSTimeInterval _duration;
    NSMutableArray *_animations;
    void (^_completionHandler)(void);
    CAMediaTimingFunction *_timingFunction;
    id _reserved;
    unsigned int _allowsImplicitAnimation:1;
    unsigned int _isImplicitContext:1;
    unsigned int __reserved:30;
}

+ (void)runAnimationGroup:(void (^)(NSAnimationContext *context))changes completionHandler:(void (^)(void))completionHandler;

+ (void)beginGrouping;
+ (void)endGrouping;

+ (NSAnimationContext *)currentContext;

@property NSTimeInterval duration;
@property(retain) CAMediaTimingFunction *timingFunction;
@property(copy) void (^completionHandler)(void);
@property BOOL allowsImplicitAnimation;

@end

#endif

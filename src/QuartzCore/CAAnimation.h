
#import <Foundation/NSString.h>
#import "CAMediaTiming.h"
#import "CAMediaTimingFunction.h"

extern "C" {

@interface CAAnimation : NSObject
    <NSCoding, NSCopying, CAMediaTiming/*, CAAction*/>
{
  @private
  void    *_attr;
  uint32_t _flags;
}

+ (id) animation;

@property(retain) CAMediaTimingFunction *timingFunction;
@property(retain) id delegate;
@property(getter=isRemovedOnCompletion) BOOL removedOnCompletion;

@end

@interface NSObject (CAAnimationDelegate)

- (void) animationDidStart: (CAAnimation*)anim;

- (void) animationDidStop: (CAAnimation*)anim
                 finished: (BOOL)flag;

@end

@interface CAPropertyAnimation : CAAnimation
@end

@interface CABasicAnimation : CAPropertyAnimation
@end

@interface CAKeyframeAnimation : CAPropertyAnimation
@end

@interface CATransition : CAAnimation

@property(copy) NSString *type;
@property(copy) NSString *subtype;
@property float startProgress;
@property float endProgress;
@property(retain) id filter;

@end

@interface CAAnimationGroup : CAAnimation
@end

extern NSString * const kCAAnimationNonZero;
extern NSString * const kCAAnimationAbsolute;
extern NSString * const kCAAnimationRelative;

extern NSString * const kCAAnimationLinear;
extern NSString * const kCAAnimationDiscrete;
extern NSString * const kCAAnimationPaced;
extern NSString * const kCAAnimationCubic;
extern NSString * const kCAAnimationCubicPaced;

extern NSString * const kCAAnimationRotateAuto;
extern NSString * const kCAAnimationRotateAutoReverse;

extern NSString * const kCATransitionFade;
extern NSString * const kCATransitionMoveIn;
extern NSString * const kCATransitionPush;
extern NSString * const kCATransitionReveal;

extern NSString * const kCATransitionFromRight;
extern NSString * const kCATransitionFromLeft;
extern NSString * const kCATransitionFromTop;
extern NSString * const kCATransitionFromBottom;

} // extern "C"

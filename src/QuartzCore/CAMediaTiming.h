
#include <CoreFoundation/CFDate.h>

#import <Foundation/NSString.h>

@protocol CAMediaTiming

@property CFTimeInterval beginTime;
@property CFTimeInterval duration;
@property float speed;
@property CFTimeInterval timeOffset;
@property float repeatCount;
@property CFTimeInterval repeatDuration;
@property BOOL autoreverses;
@property(copy) NSString *fillMode;

@end

extern "C" {

extern NSString * const kCAFillModeForwards;
extern NSString * const kCAFillModeBackwards;
extern NSString * const kCAFillModeBoth;
extern NSString * const kCAFillModeRemoved;
extern NSString * const kCAFillModeFrozen;

} // extern "C"

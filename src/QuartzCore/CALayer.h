
#import <Foundation/NSObject.h>
#import <QuartzCore/CAMediaTiming.h>

@interface CALayer : NSObject <NSCoding /*, CAMediaTiming */>
@end

@protocol CAAction

- (void) runActionForKey: (NSString*)event
                  object: (id)anObject
               arguments: (NSDictionary*)dict;

@end

extern "C" {

extern NSString * const kCAGravityCenter;
extern NSString * const kCAGravityTop;
extern NSString * const kCAGravityBottom;
extern NSString * const kCAGravityLeft;
extern NSString * const kCAGravityRight;
extern NSString * const kCAGravityTopLeft;
extern NSString * const kCAGravityTopRight;
extern NSString * const kCAGravityBottomLeft;
extern NSString * const kCAGravityBottomRight;
extern NSString * const kCAGravityResize;
extern NSString * const kCAGravityResizeAspect;
extern NSString * const kCAGravityResizeAspectFill;

extern NSString * const kCAFilterMultiplyColor;
extern NSString * const kCAFilterMultiplyGradient;
extern NSString * const kCAFilterColorAdd;
extern NSString * const kCAFilterColorSubtract;
extern NSString * const kCAFilterColorMonochrome;
extern NSString * const kCAFilterColorMatrix;
extern NSString * const kCAFilterColorHueRotate;
extern NSString * const kCAFilterColorSaturate;
extern NSString * const kCAFilterLuminanceToAlpha;
extern NSString * const kCAFilterGaussianBlur;
extern NSString * const kCAFilterLanczosResize;
extern NSString * const kCAFilterReflection;
extern NSString * const kCAFilterClear;
extern NSString * const kCAFilterCopy;
extern NSString * const kCAFilterSourceOver;
extern NSString * const kCAFilterSourceIn;
extern NSString * const kCAFilterSourceOut;
extern NSString * const kCAFilterSourceAtop;
extern NSString * const kCAFilterDestOver;
extern NSString * const kCAFilterDestIn;
extern NSString * const kCAFilterDestOut;
extern NSString * const kCAFilterDestAtop;
extern NSString * const kCAFilterXor;
extern NSString * const kCAFilterPlusL;
extern NSString * const kCAFilterSubtractS;
extern NSString * const kCAFilterSubtractD;
extern NSString * const kCAFilterMultiply;
extern NSString * const kCAFilterPlusD;

extern NSString * const kCAFilterNormalBlendMode;
extern NSString * const kCAFilterMultiplyBlendMode;
extern NSString * const kCAFilterScreenBlendMode;
extern NSString * const kCAFilterOverlayBlendMode;
extern NSString * const kCAFilterDarkenBlendMode;
extern NSString * const kCAFilterLightenBlendMode;
extern NSString * const kCAFilterColorDodgeBlendMode;
extern NSString * const kCAFilterColorBurnBlendMode;
extern NSString * const kCAFilterSoftLightBlendMode;
extern NSString * const kCAFilterHardLightBlendMode;
extern NSString * const kCAFilterDifferenceBlendMode;
extern NSString * const kCAFilterExclusionBlendMode;
extern NSString * const kCAFilterLinearBurnBlendMode;
extern NSString * const kCAFilterLinearDodgeBlendMode;
extern NSString * const kCAFilterLinearLightBlendMode;
extern NSString * const kCAFilterPinLightBlendMode;

extern NSString * const kCAFilterNearest;
extern NSString * const kCAFilterLinear;
extern NSString * const kCAFilterTrilinear;
extern NSString * const kCAFilterLanczos;

extern NSString * const kCAContentsScalingStretch;
extern NSString * const kCAContentsScalingRepeat;

extern NSString * const kCAOnOrderIn;
extern NSString * const kCAOnOrderOut;

extern NSString * const kCATransition;

} // extern "C"

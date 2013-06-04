
#import "CALayer.h"

@implementation CALayer

- (id) initWithCoder: (NSCoder*)aDecoder
{
	// TODO
	return self;
}

- (void) encodeWithCoder: (NSCoder*)aCoder
{
	// TODO
}

@end

NSString * const kCAGravityCenter              = @"center";
NSString * const kCAGravityTop                 = @"top";
NSString * const kCAGravityBottom              = @"bottom";
NSString * const kCAGravityLeft                = @"left";
NSString * const kCAGravityRight               = @"right";
NSString * const kCAGravityTopLeft             = @"topLeft";
NSString * const kCAGravityTopRight            = @"topRight";
NSString * const kCAGravityBottomLeft          = @"bottomLeft";
NSString * const kCAGravityBottomRight         = @"bottomRight";
NSString * const kCAGravityResize              = @"resize";
NSString * const kCAGravityResizeAspect        = @"resizeAspect";
NSString * const kCAGravityResizeAspectFill    = @"resizeAspectFill";

NSString * const kCAFilterMultiplyColor        = @"multiplyColor";
NSString * const kCAFilterMultiplyGradient     = @"multiplyGradient";
NSString * const kCAFilterColorAdd             = @"colorAdd";
NSString * const kCAFilterColorSubtract        = @"colorSubtract";
NSString * const kCAFilterColorMonochrome      = @"colorMonochrome";
NSString * const kCAFilterColorMatrix          = @"colorMatrix";
NSString * const kCAFilterColorHueRotate       = @"colorHueRotate";
NSString * const kCAFilterColorSaturate        = @"colorSaturate";
NSString * const kCAFilterLuminanceToAlpha     = @"luminanceToAlpha";
NSString * const kCAFilterGaussianBlur         = @"gaussianBlur";
NSString * const kCAFilterLanczosResize        = @"lanczosResize";
NSString * const kCAFilterReflection           = @"reflection";
NSString * const kCAFilterClear                = @"clear";
NSString * const kCAFilterCopy                 = @"copy";
NSString * const kCAFilterSourceOver           = @"sourceOver";
NSString * const kCAFilterSourceIn             = @"sourceIn";
NSString * const kCAFilterSourceOut            = @"sourceOut";
NSString * const kCAFilterSourceAtop           = @"sourceAtop";
NSString * const kCAFilterDestOver             = @"destOver";
NSString * const kCAFilterDestIn               = @"destIn";
NSString * const kCAFilterDestOut              = @"destOut";
NSString * const kCAFilterDestAtop             = @"destAtop";
NSString * const kCAFilterXor                  = @"xor";
NSString * const kCAFilterPlusL                = @"plusL";
NSString * const kCAFilterSubtractS            = @"subtractS";
NSString * const kCAFilterSubtractD            = @"subtractD";
NSString * const kCAFilterMultiply             = @"multiply";
NSString * const kCAFilterPlusD                = @"plusD";

NSString * const kCAFilterNormalBlendMode      = @"normalBlendMode";
NSString * const kCAFilterMultiplyBlendMode    = @"multiplyBlendMode";
NSString * const kCAFilterScreenBlendMode      = @"screenBlendMode";
NSString * const kCAFilterOverlayBlendMode     = @"overlayBlendMode";
NSString * const kCAFilterDarkenBlendMode      = @"darkenBlendMode";
NSString * const kCAFilterLightenBlendMode     = @"lightenBlendMode";
NSString * const kCAFilterColorDodgeBlendMode  = @"colorDodgeBlendMode";
NSString * const kCAFilterColorBurnBlendMode   = @"colorBurnBlendMode";
NSString * const kCAFilterSoftLightBlendMode   = @"softLightBlendMode";
NSString * const kCAFilterHardLightBlendMode   = @"hardLightBlendMode";
NSString * const kCAFilterDifferenceBlendMode  = @"differenceBlendMode";
NSString * const kCAFilterExclusionBlendMode   = @"exclusionBlendMode";
NSString * const kCAFilterLinearBurnBlendMode  = @"linearBurnBlendMode";
NSString * const kCAFilterLinearDodgeBlendMode = @"linearDodgeBlendMode";
NSString * const kCAFilterLinearLightBlendMode = @"linearLightBlendMode";
NSString * const kCAFilterPinLightBlendMode    = @"pinLightBlendMode";

NSString * const kCAFilterNearest              = @"nearest";
NSString * const kCAFilterLinear               = @"linear";
NSString * const kCAFilterTrilinear            = @"trilinear";
NSString * const kCAFilterLanczos              = @"lanczos";

NSString * const kCAContentsScalingStretch     = @"stretch";
NSString * const kCAContentsScalingRepeat      = @"repeat";

NSString * const kCAOnOrderIn                  = @"onOrderIn";
NSString * const kCAOnOrderOut                 = @"onOrderOut";

NSString * const kCATransition                 = @"transition";

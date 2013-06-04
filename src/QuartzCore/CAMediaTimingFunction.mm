
#import "CAMediaTimingFunction.h"

struct CAMediaTimingFunctionPrivate
{
	float c1x, c1y, c2x, c2y;
};

@implementation CAMediaTimingFunction

- (id) initWithCoder: (NSCoder*)aDecoder
{
	// TODO
	return self;
}

- (void) encodeWithCoder: (NSCoder*)aCoder
{
	// TODO
}

+ (id) functionWithName: (NSString*)name
{
	// TODO: get the named function
	return [self functionWithControlPoints: 0.5f : 0.5f : 0.5f : 0.5f];
}

+ (id) functionWithControlPoints: (float)c1x
                                : (float)c1y
                                : (float)c2x
                                : (float)c2y
{
	return [[[self alloc] initWithControlPoints: c1x : c1y : c2x : c2y] autorelease];
}

- (id) initWithControlPoints: (float)c1x
                            : (float)c1y
                            : (float)c2x
                            : (float)c2y
{
	self = [super init];

	if (nil != self)
	{
		_priv = new CAMediaTimingFunctionPrivate;
		_priv->c1x = c1x;
		_priv->c1y = c1y;
		_priv->c2x = c2x;
		_priv->c2y = c2y;
	}

	return self;
}

- (void) getControlPointAtIndex: (size_t)idx
                         values: (float[2])ptr
{
	switch (idx)
	{
		case 0:
		default:
			ptr[0] = 0.0f;
			ptr[1] = 0.0f;
			break;

		case 1:
			ptr[0] = _priv->c1x;
			ptr[1] = _priv->c1y;
			break;

		case 2:
			ptr[0] = _priv->c2x;
			ptr[1] = _priv->c2y;
			break;

		case 3:
			ptr[0] = 1.0f;
			ptr[1] = 1.0f;
			break;
	}
}

@end

NSString * const kCAMediaTimingFunctionLinear        = @"linear";
NSString * const kCAMediaTimingFunctionEaseIn        = @"easeIn";
NSString * const kCAMediaTimingFunctionEaseOut       = @"easeOut";
NSString * const kCAMediaTimingFunctionEaseInEaseOut = @"easeInEaseOut";
NSString * const kCAMediaTimingFunctionDefault       = @"default";

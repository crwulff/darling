
#import <Foundation/NSObject.h>

@interface CAMediaTimingFunction : NSObject <NSCoding>
{
@private
  struct CAMediaTimingFunctionPrivate *_priv;
}

+ (id) functionWithName: (NSString*)name;

+ (id) functionWithControlPoints: (float)c1x
                                : (float)c1y
                                : (float)c2x
                                : (float)c2y;

- (id) initWithControlPoints: (float)c1x
                            : (float)c1y
                            : (float)c2x
                            : (float)c2y;

- (void) getControlPointAtIndex: (size_t)idx
                         values: (float[2])ptr;

@end

#ifdef __cplusplus
extern "C" {
#endif

extern NSString * const kCAMediaTimingFunctionLinear;
extern NSString * const kCAMediaTimingFunctionEaseIn;
extern NSString * const kCAMediaTimingFunctionEaseOut;
extern NSString * const kCAMediaTimingFunctionEaseInEaseOut;
extern NSString * const kCAMediaTimingFunctionDefault;

#ifdef __cplusplus
} // extern "C"
#endif

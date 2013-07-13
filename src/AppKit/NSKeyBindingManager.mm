
#import "NSKeyBindingManager.h"

@implementation NSKeyBindingManager

+ (NSKeyBindingManager*) sharedKeyBindingManager
{
  return [[NSKeyBindingManager alloc] init]; // TODO - For now just return a new one each time
}

- (NSDictionary*) dictionary
{
  return _dict;
}

- (void) setDictionary: (NSDictionary*)dictionary
{
  [_dict autorelease];
  _dict = [dictionary retain];
}

@end


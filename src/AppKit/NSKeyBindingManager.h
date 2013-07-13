
#ifndef _KeyBindingManager_H_
#define _KeyBindingManager_H_

#import <Foundation/NSObject.h>

@class NSDictionary;

@interface NSKeyBindingManager : NSObject {
  @private
  NSDictionary *_dict;
}

+ (NSKeyBindingManager*) sharedKeyBindingManager;

- (NSDictionary*) dictionary;

- (void) setDictionary: (NSDictionary*)dictionary;

@end

#endif

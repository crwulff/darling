
#import <AppKit/NSDocumentController.h>
#import <Foundation/NSArray.h>

@interface NSDocumentController (NSPrivate)

- (NSArray*) _recentDocumentURLsForKey: (NSString*) key;

@end

@implementation NSDocumentController (NSPrivate)

- (NSArray*) _recentDocumentURLsForKey: (NSString*) key
{
  // TODO
  return [NSMutableArray array];
}

@end

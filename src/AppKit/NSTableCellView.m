
#import <Foundation/NSObject.h>
#import <AppKit/NSNibDeclarations.h>

#import <AppKit/NSView.h>
#import <AppKit/NSCell.h>
#import <AppKit/NSTableView.h>

@class NSTextField, NSImageView;

typedef NSInteger NSTableViewRowSizeStyle;
typedef NSInteger NSBackgroundStyle;

@interface NSTableCellView : NSView
{
  @private
  NSBackgroundStyle _backgroundStyle;
  id _objectValue;
  id _aux;
  NSTableViewRowSizeStyle _rowSizeStyle;
  NSTextField *_textField;
  NSImageView *_imageView;
}

@property(retain) id objectValue;
@property(assign) IBOutlet NSTextField *textField;
@property(assign) IBOutlet NSImageView *imageView;
@property NSBackgroundStyle backgroundStyle;
@property NSTableViewRowSizeStyle rowSizeStyle;
@property(retain, readonly) NSArray *draggingImageComponents;

@end

@implementation NSTableCellView

@synthesize objectValue = _objectValue;
@synthesize backgroundStyle = _backgroundStyle;
@synthesize rowSizeStyle = _rowSizeStyle;
@synthesize textField = _textField;
@synthesize imageView = _imageView;

- (NSArray*) draggingImageComponents
{
  // TODO
  return nil;
}

@end


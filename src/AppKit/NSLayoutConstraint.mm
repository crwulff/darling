
#import <Foundation/NSObject.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSString.h>

typedef NSInteger NSLayoutRelation;
typedef NSInteger NSLayoutAttribute;
typedef NSUInteger NSLayoutFormatOptions;
typedef float NSLayoutPriority;

@interface NSLayoutConstraint : NSObject //<NSAnimatablePropertyContainer>
{
  @private

  id _container;
  id _firstItem;
  id _secondItem;
  CGFloat _constant;
  CGFloat _loweredConstant;
  id _markerAndPositiveExtraVar;
  id _negativeExtraVar;
  float _coefficient;
  NSLayoutPriority _priority;
  uint64_t _layoutConstraintFlags;
  id _flange;
}

+ (NSArray*) constraintsWithVisualFormat: (NSString*)format
				 options: (NSLayoutFormatOptions)opts
				 metrics: (NSDictionary*)metrics
				   views: (NSDictionary*)views;

+ (id) constraintWithItem: (id)view1
		attribute: (NSLayoutAttribute)attr1
		relatedBy: (NSLayoutRelation)relation
		   toItem: (id)view2
		attribute: (NSLayoutAttribute)attr2
	       multiplier: (CGFloat)multiplier
		 constant: (CGFloat)c;

@property NSLayoutPriority priority;
@property BOOL shouldBeArchived;
@property (readonly, assign) id firstItem;
@property (readonly) NSLayoutAttribute firstAttribute;
@property (readonly) NSLayoutRelation relation;
@property (readonly, assign) id secondItem;
@property (readonly) NSLayoutAttribute secondAttribute;
@property (readonly) CGFloat multiplier;
@property CGFloat constant;

@end

@implementation NSLayoutConstraint

+ (NSArray*) constraintsWithVisualFormat: (NSString*)format
				 options: (NSLayoutFormatOptions)opts
				 metrics: (NSDictionary*)metrics
				   views: (NSDictionary*)views
{
  // TODO
  return nil;
}

+ (id) constraintWithItem: (id)view1
		attribute: (NSLayoutAttribute)attr1
		relatedBy: (NSLayoutRelation)relation
		   toItem: (id)view2
		attribute: (NSLayoutAttribute)attr2
	       multiplier: (CGFloat)multiplier
		 constant: (CGFloat)c
{
  NSLayoutConstraint *constraint = [NSLayoutConstraint alloc];

  constraint->_firstItem = view1;
  constraint->_secondItem = view2;
  constraint->_constant = c;
  constraint->_loweredConstant = 0;
  constraint->_markerAndPositiveExtraVar = 0;
  constraint->_negativeExtraVar = 0;
  constraint->_coefficient = multiplier;
  constraint->_priority = 0;
  constraint->_layoutConstraintFlags = (attr1) | (attr2 << 8) | (relation << 30);
  constraint->_flange = 0;

  return constraint;
}

@synthesize firstItem = _firstItem;
@synthesize secondItem = _secondItem;
@synthesize constant = _constant;
@synthesize priority = _priority;

- (CGFloat) multiplier
{
  return _coefficient;
}

- (NSLayoutAttribute) firstAttribute
{
  return _layoutConstraintFlags & 0xFF;
}

- (NSLayoutAttribute) secondAttribute
{
  return (_layoutConstraintFlags >> 8) & 0xFF;
}

- (NSLayoutRelation) relation
{
  return (_layoutConstraintFlags >> 30) & 0x7FFF;
}

- (BOOL) shouldBeArchived
{
  return (_layoutConstraintFlags >> 19) & 1;
}

- (void) setShouldBeArchived: (BOOL)archive
{
  if (archive)
  {
    _layoutConstraintFlags |= 1 << 19;
  }
}

@end

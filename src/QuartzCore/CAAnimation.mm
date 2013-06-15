
#import "CAAnimation.h"
#import <Foundation/NSException.h>

#include "CAAtoms.h"
#include "CATransaction.h"
#include "CAAttrList.h"

#include <map>

typedef enum {
	kCAAnimationImmutable = 1,
} CAAnimationFlags;

@implementation CAAnimation

+ (id) animation
{
	return [[[self alloc] init] autorelease];
}

- (id) initWithCoder: (NSCoder*)aDecoder
{
	// TODO
	return self;
}

- (void) encodeWithCoder: (NSCoder*)aCoder
{
	// TODO
}

- (id) copyWithZone: (NSZone*)zone
{
	// TODO
	return [[[CAAnimation allocWithZone: zone] init] autorelease];
}

- (void) getter: (CAAtom) atom
      valueType: (CAValueType) valueType
          value: (void *) value
{
	Darling::MutexLock lock(CA::Transaction::ensure());

	if (_attr)
	{
		((CA::AttrList*)_attr)->get(atom, valueType, value);
	}
}

- (void) setter: (CAAtom) atom
      valueType: (CAValueType) valueType
          value: (const void *) value
{
	if (_flags & kCAAnimationImmutable)
	{
		[NSException raise: @"CAAnimationImmutable" format: @"attempting to modify read-only animation %@", self];
	}

	{ Darling::MutexLock lock(CA::Transaction::ensure());

		if (!_attr)
		{
			_attr = (void*)new CA::AttrList();
		}

		((CA::AttrList*)_attr)->set(atom, valueType, value);
	}

	[self didChangeValueForKey: CAAtomGetString(atom)];

	switch (atom)
	{
		case kCAAtom_autoreverses:
		case kCAAtom_beginTime:
		case kCAAtom_duration:
		case kCAAtom_fillMode:
		case kCAAtom_repeatCount:
		case kCAAtom_repeatDuration:
		case kCAAtom_speed:
		case kCAAtom_timeOffset:
			// TODO: CAMediaTimingInvalidate(self);
			break;

		default:
			break;
	}
}

- (CAMediaTimingFunction*) timingFunction
{
	CAMediaTimingFunction *timingFunction = nil;

	[self getter: kCAAtom_timingFunction valueType: kCAValueTypeRetainedPointer value: &timingFunction];

	return timingFunction;
}

- (void) setTimingFunction: (CAMediaTimingFunction*) timingFunction
{
	[self setter: kCAAtom_timingFunction valueType: kCAValueTypeRetainedPointer value: &timingFunction];
}

- (id) delegate
{
	id delegate = nil;

	[self getter: kCAAtom_delegate valueType: kCAValueTypeRetainedPointer value: &delegate];

	return delegate;
}

- (void) setDelegate: (id) delegate
{
	[self setter: kCAAtom_delegate valueType: kCAValueTypeRetainedPointer value: &delegate];
}

- (BOOL) isRemovedOnCompletion
{
	BOOL removedOnCompletion = false;

	[self getter: kCAAtom_removedOnCompletion valueType: kCAValueTypeBool value: &removedOnCompletion];

	return removedOnCompletion;
}

- (BOOL) removedOnCompletion
{
	return [self isRemovedOnCompletion];
}

- (void) setRemovedOnCompletion: (BOOL) removedOnCompletion
{
	[self setter: kCAAtom_removedOnCompletion valueType: kCAValueTypeBool value: &removedOnCompletion];
}

- (CFTimeInterval) beginTime
{
	CFTimeInterval beginTime = 0.0;

	[self getter: kCAAtom_beginTime valueType: kCAValueTypeDouble value: &beginTime];

	return beginTime;
}

- (void) setBeginTime: (CFTimeInterval) beginTime
{
	[self setter: kCAAtom_beginTime valueType: kCAValueTypeDouble value: &beginTime];
}

- (CFTimeInterval) duration
{
	CFTimeInterval duration = 0.0;

	[self getter: kCAAtom_duration valueType: kCAValueTypeDouble value: &duration];

	return duration;
}

- (void) setDuration: (CFTimeInterval) duration
{
	[self setter: kCAAtom_duration valueType: kCAValueTypeDouble value: &duration];
}

- (float) speed
{
	float speed = 0.0f;

	[self getter: kCAAtom_speed valueType: kCAValueTypeFloat value: &speed];

	return speed;
}

- (void) setSpeed: (float) speed
{
	[self setter: kCAAtom_speed valueType: kCAValueTypeFloat value: &speed];
}

- (CFTimeInterval) timeOffset
{
	CFTimeInterval timeOffset = 0.0;

	[self getter: kCAAtom_timeOffset valueType: kCAValueTypeDouble value: &timeOffset];

	return timeOffset;
}

- (void) setTimeOffset: (CFTimeInterval) timeOffset
{
	[self setter: kCAAtom_timeOffset valueType: kCAValueTypeDouble value: &timeOffset];
}

- (float) repeatCount
{
	float repeatCount = 0.0f;

	[self getter: kCAAtom_repeatCount valueType: kCAValueTypeFloat value: &repeatCount];

	return repeatCount;
}

- (void) setRepeatCount: (float) repeatCount
{
	[self setter: kCAAtom_repeatCount valueType: kCAValueTypeFloat value: &repeatCount];
}

- (CFTimeInterval) repeatDuration
{
	CFTimeInterval repeatDuration = 0.0;

	[self getter: kCAAtom_repeatDuration valueType: kCAValueTypeDouble value: &repeatDuration];

	return repeatDuration;
}

- (void) setRepeatDuration: (CFTimeInterval) repeatDuration
{
	[self setter: kCAAtom_repeatDuration valueType: kCAValueTypeDouble value: &repeatDuration];
}

- (BOOL) autoreverses
{
	BOOL autoreverses = false;

	[self getter: kCAAtom_autoreverses valueType: kCAValueTypeBool value: &autoreverses];

	return autoreverses;
}

- (void) setAutoreverses: (BOOL) autoreverses
{
	[self setter: kCAAtom_autoreverses valueType: kCAValueTypeBool value: &autoreverses];
}

- (NSString*) fillMode
{
	NSString* fillMode = nil;

	[self getter: kCAAtom_fillMode valueType: kCAValueTypeCopiedPointer value: &fillMode];

	return fillMode;
}

- (void) setFillMode: (NSString*) fillMode
{
	[self setter: kCAAtom_fillMode valueType: kCAValueTypeCopiedPointer value: &fillMode];
}

@end

@implementation NSObject (CAAnimationDelegate)

- (void) animationDidStart: (CAAnimation*)anim
{
}

- (void) animationDidStop: (CAAnimation*)anim
                 finished: (BOOL)flag
{
}

@end

@implementation CAPropertyAnimation
@end

@implementation CABasicAnimation
@end

@implementation CAKeyframeAnimation
@end

@implementation CATransition
- (NSString *) type
{
	NSString *type = nil;

	[self getter: kCAAtom_type valueType: kCAValueTypeCopiedPointer value: &type];

	return type;
}

- (void) setType: (NSString*) type
{
	[self setter: kCAAtom_type valueType: kCAValueTypeCopiedPointer value: &type];
}

- (NSString *) subtype
{
	NSString *subtype = nil;

	[self getter: kCAAtom_subtype valueType: kCAValueTypeCopiedPointer value: &subtype];

	return subtype;
}

- (void) setSubtype: (NSString*) subtype
{
	[self setter: kCAAtom_subtype valueType: kCAValueTypeCopiedPointer value: &subtype];
}

- (float) startProgress
{
	float startProgress = 0.0f;

	[self getter: kCAAtom_startProgress valueType: kCAValueTypeFloat value: &startProgress];

	return startProgress;
}

- (void) setStartProgress: (float) startProgress
{
	[self setter: kCAAtom_startProgress valueType: kCAValueTypeFloat value: &startProgress];
}

- (float) endProgress
{
	float endProgress = 0.0f;

	[self getter: kCAAtom_endProgress valueType: kCAValueTypeFloat value: &endProgress];

	return endProgress;
}

- (void) setEndProgress: (float) endProgress
{
	[self setter: kCAAtom_endProgress valueType: kCAValueTypeFloat value: &endProgress];
}

- (id) filter
{
	id filter = nil;

	[self getter: kCAAtom_filter valueType: kCAValueTypeRetainedPointer value: &filter];

	return filter;
}

- (void) setFilter: (id) filter
{
	[self setter: kCAAtom_filter valueType: kCAValueTypeRetainedPointer value: &filter];
}

@end

@implementation CAAnimationGroup
@end

NSString * const kCAAnimationNonZero           = @"non-zero";
NSString * const kCAAnimationAbsolute          = @"absolute";
NSString * const kCAAnimationRelative          = @"relative";

NSString * const kCAAnimationLinear            = @"linear";
NSString * const kCAAnimationDiscrete          = @"discrete";
NSString * const kCAAnimationPaced             = @"paced";
NSString * const kCAAnimationCubic             = @"cubic";
NSString * const kCAAnimationCubicPaced        = @"cubicPaced";

NSString * const kCAAnimationRotateAuto        = @"auto";
NSString * const kCAAnimationRotateAutoReverse = @"autoReverse";

NSString * const kCATransitionFade             = @"fade";
NSString * const kCATransitionMoveIn           = @"moveIn";
NSString * const kCATransitionPush             = @"push";
NSString * const kCATransitionReveal           = @"reveal";

NSString * const kCATransitionFromRight        = @"fromRight";
NSString * const kCATransitionFromLeft         = @"fromLeft";
NSString * const kCATransitionFromTop          = @"fromTop";
NSString * const kCATransitionFromBottom       = @"fromBottom";

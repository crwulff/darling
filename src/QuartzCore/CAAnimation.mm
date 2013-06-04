
#import "CAAnimation.h"
#import <Foundation/NSException.h>

extern "C" {
#import <CoreGraphics/CGAffineTransform.h>
}

#include "CAAtoms.h"
#include "CATransaction.h"

#include <map>
#include <Block.h>

typedef enum {
	kCAValueTypeAssignedPointer  = 1,
	kCAValueTypeRetainedPointer  = 2,
	kCAValueTypeCopiedPointer    = 3,
	kCAValueTypeBlock            = 4,
	kCAValueTypeBool             = 5,
	kCAValueTypeChar             = 6,
	kCAValueTypeUnsignedChar     = 7,
	kCAValueTypeShort            = 8,
	kCAValueTypeUnsignedShort    = 9,
	kCAValueTypeInt              = 10,
	kCAValueTypeUnsignedInt      = 11,
	kCAValueTypeLong             = 12,
	kCAValueTypeUnsignedLong     = 13,
	kCAValueTypeLongLong         = 14,
	kCAValueTypeUnsignedLongLong = 15,
	kCAValueTypeFloat            = 16,
	kCAValueTypeDouble           = 17,
	kCAValueTypePoint            = 18,
	kCAValueTypeSize             = 19,
	kCAValueTypeRect             = 20,
	kCAValueTypeTransform        = 21,
	kCAValueTypeAffineTransform  = 22,
	kCAValueTypePoint3D          = 23,
} CAValueType;

typedef enum {
	kCAAnimationImmutable = 1,
} CAAnimationFlags;

namespace CA {

class Point
{
	public:
		Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

	private:
		double x, y;
};

class Point3D
{
	public:
		Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

	private:
		double x, y, z;
};

class Size
{
	public:
		Size(double sx = 0.0, double sy = 0.0) : sx(sx), sy(sy) {}

	private:
		double sx, sy;
};

class Rect
{
	public:
		Rect(Point p1, Point p2) : p1(p1), p2(p2) {}

	private:
		Point p1, p2;
};

class Mat4Impl
{
	public:
		Mat4Impl(double matrix[16]) { for (int i = 0; i<16; i++) { this->matrix[i] = matrix[i]; } }

		Mat4Impl(const Mat4Impl *rhs) { for (int i = 0; i<16; i++) { this->matrix[i] = rhs->matrix[i]; } }

		Mat4Impl * operator=(const Mat4Impl *rhs) { if (this != rhs) { for (int i = 0; i<16; i++) { this->matrix[i] = rhs->matrix[i]; } } return this; }

	private:
		double matrix[16];
};

class AttrList
{

	private:
		typedef union CAAtomValue
		{
			id                 obj;
			CFTypeRef          cf;
			void              *block;
			bool               b;
			char               c;
			unsigned char      uc;
			short              s;
			unsigned short     us;
			int                i;
			unsigned int       ui;
			long               l;
			unsigned long      ul;
			long long          ll;
			unsigned long long ull;
			float              f;
			double             d;
			Point              p;
			Size               sz;
			Rect               r;
			Mat4Impl           t;
			CGAffineTransform  at;
			Point3D            p3d;

			CAAtomValue(void) { obj = nil; }

		} CAAtomValue;

	public:
		void set(CAAtom atom, CAValueType valueType, const void *value)
		{
			const CAAtomValue *_value = (const CAAtomValue*)value;

			switch (valueType)
			{
				case kCAValueTypeAssignedPointer:
					values[atom].cf = _value->cf;
					break;

				case kCAValueTypeRetainedPointer:
					if (values[atom].cf != _value->cf)
					{
						if (values[atom].cf)
						{
							Transaction::cf_release(values[atom].cf);
						}

						values[atom].cf = CFRetain(_value->cf);
					}
					break;

				case kCAValueTypeCopiedPointer:
					if (values[atom].cf != _value->cf)
					{
						if (values[atom].cf)
						{
							Transaction::cf_release(values[atom].cf);
						}

						if (_value->cf)
						{
							if ([_value->obj respondsToSelector: @selector(copyWithZone:)])
							{
								values[atom].obj = [_value->obj copy];
							}
							else
							{
								values[atom].cf = CFRetain(_value->cf);
							}
						}
						else
						{
							values[atom].cf = 0;
						}
					}
					break;

				case kCAValueTypeBlock:
					if (values[atom].block != _value->block)
					{
						if (values[atom].block)
						{
							_Block_release(values[atom].block);
						}

						if (_value->block)
						{
							values[atom].block = _Block_copy(_value->block);
						}
						else
						{
							values[atom].block = 0;
						}
					}
					break;

				case kCAValueTypeBool:
					values[atom].b = _value->b;
					break;

				case kCAValueTypeChar:
					values[atom].c = _value->c;
					break;

				case kCAValueTypeUnsignedChar:
					values[atom].uc = _value->uc;
					break;

				case kCAValueTypeShort:
					values[atom].s = _value->s;
					break;

				case kCAValueTypeUnsignedShort:
					values[atom].us = _value->us;
					break;

				case kCAValueTypeInt:
					values[atom].i = _value->i;
					break;

				case kCAValueTypeUnsignedInt:
					values[atom].ui = _value->ui;
					break;

				case kCAValueTypeLong:
					values[atom].l = _value->l;
					break;

				case kCAValueTypeUnsignedLong:
					values[atom].ul = _value->ul;
					break;

				case kCAValueTypeLongLong:
					values[atom].ll = _value->ll;
					break;

				case kCAValueTypeUnsignedLongLong:
					values[atom].ull = _value->ull;
					break;

				case kCAValueTypeFloat:
					values[atom].f = _value->f;
					break;

				case kCAValueTypeDouble:
					values[atom].d = _value->d;
					break;

				case kCAValueTypePoint:
					values[atom].p = _value->p;
					break;

				case kCAValueTypeSize:
					values[atom].sz = _value->sz;
					break;

				case kCAValueTypeRect:
					values[atom].r = _value->r;
					break;

				case kCAValueTypeTransform:
					values[atom].t = _value->t;
					break;

				case kCAValueTypeAffineTransform:
					values[atom].at = _value->at;
					break;

				case kCAValueTypePoint3D:
					values[atom].p3d = _value->p3d;
					break;

				default:
					break;
			}
		}

		bool get(CAAtom atom, CAValueType valueType, void *value)
		{
			CAAtomValue *_value = (CAAtomValue*)value;

			if (values.end() == values.find(atom)) return false;

			switch (valueType)
			{
				case kCAValueTypeAssignedPointer:
					_value->cf = values[atom].cf;
					break;

				case kCAValueTypeRetainedPointer:
					_value->cf = values[atom].cf;
					break;

				case kCAValueTypeCopiedPointer:
					_value->cf = values[atom].cf;
					break;

				case kCAValueTypeBlock:
					_value->block = values[atom].block;
					break;

				case kCAValueTypeBool:
					_value->b = values[atom].b;
					break;

				case kCAValueTypeChar:
					_value->c = values[atom].c;
					break;

				case kCAValueTypeUnsignedChar:
					_value->uc = values[atom].uc;
					break;

				case kCAValueTypeShort:
					_value->s = values[atom].s;
					break;

				case kCAValueTypeUnsignedShort:
					_value->us = values[atom].us;
					break;

				case kCAValueTypeInt:
					_value->i = values[atom].i;
					break;

				case kCAValueTypeUnsignedInt:
					_value->ui = values[atom].ui;
					break;

				case kCAValueTypeLong:
					_value->l = values[atom].l;
					break;

				case kCAValueTypeUnsignedLong:
					_value->ul = values[atom].ul;
					break;

				case kCAValueTypeLongLong:
					_value->ll = values[atom].ll;
					break;

				case kCAValueTypeUnsignedLongLong:
					_value->ull = values[atom].ull;
					break;

				case kCAValueTypeFloat:
					_value->f = values[atom].f;
					break;

				case kCAValueTypeDouble:
					_value->d = values[atom].d;
					break;

				case kCAValueTypePoint:
					_value->p = values[atom].p;
					break;

				case kCAValueTypeSize:
					_value->sz = values[atom].sz;
					break;

				case kCAValueTypeRect:
					_value->r = values[atom].r;
					break;

				case kCAValueTypeTransform:
					_value->t = values[atom].t;
					break;

				case kCAValueTypeAffineTransform:
					_value->at = values[atom].at;
					break;

				case kCAValueTypePoint3D:
					_value->p3d = values[atom].p3d;
					break;

				default:
					return false;
			}

			return true;
		}

	private:
		std::map<CAAtom, CAAtomValue> values;
};

} // namespace CA

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

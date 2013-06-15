
#include "CAAttrList.h"
#include "CATransaction.h"

#include <Block.h>

namespace CA {

void AttrList::set(CAAtom atom, CAValueType valueType, const void *value)
{
	const CAAtomValue *_value = (const CAAtomValue*)value;

	NSLog(@"Set %@ (%03X) (type %d)", CAAtomGetString(atom), atom, valueType);

	switch (valueType)
	{
		case kCAValueTypeAssignedPointer:
			NSLog(@"Set %@ (%03X) (type %d) = %p", CAAtomGetString(atom), atom, valueType, _value->cf);
			values[atom].cf = _value->cf;
			break;

		case kCAValueTypeRetainedPointer:
			NSLog(@"Set %@ (%03X) (type %d) = %p (prev %p)", CAAtomGetString(atom), atom, valueType, _value->cf, values[atom].cf);
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
			NSLog(@"Set %@ (%03X) (type %d) = %p (prev %p)", CAAtomGetString(atom), atom, valueType, _value->cf, values[atom].cf);
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

bool AttrList::get(CAAtom atom, CAValueType valueType, void *value)
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

} // namespace CA


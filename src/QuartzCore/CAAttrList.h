
#ifndef _CAAttrList_H_
#define _CAAttrList_H_

extern "C" {
#include <CoreGraphics/CGAffineTransform.h>
}

#include <map>

#include "CAAtoms.h"

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
			CAAtomValue(void) { obj = nil; }

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

		} CAAtomValue;

	public:
		void set(CAAtom atom, CAValueType valueType, const void *value);

		bool get(CAAtom atom, CAValueType valueType, void *value);

	private:
		std::map<CAAtom, CAAtomValue> values;
};

} // namespace CA

#endif

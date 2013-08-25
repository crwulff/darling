#include "./class.h"
#include "../../util/trace.h"
#include "../../util/log.h"
#include <map>
#include <algorithm>
#include "../common/method.h"
#include "../common/property.h"
#include "../common/ref.h"
#include "./ivar.h"
#include "./protocol.h"
#include "../TopologySort.h"

extern std::map<const void*,Class> g_classPointers;

Class RegisterClass(const class_t* cls, intptr_t slide, uint32_t image_index)
{
	if (nullptr == cls)
	{
		return nullptr;
	}

	auto itClass = g_classPointers.find(cls);
	if (itClass != g_classPointers.end())
	{
		LOG << "Found existing class @" << itClass->second << std::endl;
		return itClass->second;
	}

	Class super = RegisterClass(cls->superclass, slide, image_index);

	LOG << "...superclass is @" << super << std::endl;
	if (nullptr != super)
	{
		LOG << "...superclass name " << (((uintptr_t)super != (uintptr_t)cls->superclass) ? cls->superclass->data()->className : class_getName(super)) << std::endl;
		LOG << "...super name " << class_getName(super) << std::endl;
	}

	if (nullptr == cls->data())
	{
		// TODO: Is this a bad pointer filled in, or are we supposed to do something different with this?
		// This is from when we call RegisterClass recursively sometimes...
		std::cerr << "Error - Null class data at class @" << cls << std::endl;
		return nullptr;
	}

	if (nullptr == cls->data()->className)
	{
		// TODO: Is this a bad pointer filled in, or are we supposed to do something different with this?
		// This is from when we call RegisterClass recursively sometimes...
		std::cerr << "Error - Null class name at class @" << cls << std::endl;
		return nullptr;
	}

	LOG << "Processing ObjC class " << cls->data()->className << std::endl;

	Class sameClass = (Class)objc_getClass(cls->data()->className);
	if (nullptr != sameClass)
	{
		LOG << "Found a class with the same name @" << sameClass << std::endl;
		return sameClass;
	}

	LOG << "obj_allocateClassPair(" << super << ", " << cls->data()->className << ")" << std::endl;

	Class conv = objc_allocateClassPair(super, cls->data()->className, 0);

	if (nullptr == conv)
	{
		std::cerr << "Failed to allocate class " << cls->data()->className << std::endl;
		return nullptr;
	}

	Class meta = object_getClass(id(conv));

	const class_ro_t* ro = cls->data();

	if (ro->baseMethods)
		ConvertMethodListGen(conv, ro->baseMethods, image_index);
	if (g_classPointers.find(cls->isa) == g_classPointers.end())
	{
		const class_ro_t* roMeta = cls->isa->data();
		if (roMeta->baseMethods)
			ConvertMethodListGen(meta, roMeta->baseMethods, image_index);
	}
	if (ro->ivars)
		ConvertIvarList(conv, ro->ivars);
	if (ro->baseProtocols)
		AddClassProtocols(conv, ro->baseProtocols, slide);
	if (ro->baseProperties)
	{
		ConvertProperties(ro->baseProperties, [conv](const char* name, const objc_property_attribute_t* attr, unsigned int count) { class_addProperty(conv, name, attr, count); bug_gnustepFixPropertyCount(conv); });
	}

	// conv->instance_size = ro->instSize;

	objc_registerClassPair(conv);
	
	LOG << "ObjC class " << cls->data()->className << " now @" << conv << std::endl;
	g_classPointers[cls] = conv;
	g_classPointers[conv] = conv;
	g_classPointers[meta] = meta;

	return conv;
}

std::vector<const char*> ProcessClassesNew(const struct mach_header* mh, intptr_t slide, const char* segment, const char* section, uint32_t image_index)
{
	class_t **classes, **classes_end;
	unsigned long size;
	std::vector<const char*> classNames;

	classes = reinterpret_cast<class_t**>(
		getsectdata(mh, segment, section, &size)
	);

	if (nullptr != classes)
	{
		classes_end = classes + size / sizeof(class_t*);

		while (classes < classes_end)
		{
			Class c = RegisterClass(*classes, slide, image_index);
			classNames.push_back(class_getName(c));
			LOG << "Fixup @" << classes << " " << *classes << " -> " << c <<std::endl;
			*classes = (class_t*)c;

			classes++;
		}
	}

	return classNames;
}


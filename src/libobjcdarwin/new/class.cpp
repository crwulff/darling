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

Class RegisterClass(const class_t* cls, intptr_t slide)
{
	LOG << "Processing ObjC class " << cls->data()->className << std::endl;
	
	const class_t* meta = cls->isa;
	Class conv, super = nullptr;
	auto itSuper = g_classPointers.find(cls->superclass);

	if (itSuper != g_classPointers.end())
	{
		super = itSuper->second;
	}
	else if (nullptr != cls->superclass)
	{
		super = RegisterClass(cls->superclass, 0);
	}
	
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
		std::cout << "Error - Null class data at class @" << cls << std::endl;
		return nullptr;
	}

	if (nullptr == cls->data()->className)
	{
		// TODO: Is this a bad pointer filled in, or are we supposed to do something different with this?
		// This is from when we call RegisterClass recursively sometimes...
		std::cout << "Error - Null class name at class @" << cls << std::endl;
		return nullptr;
	}

	conv = objc_allocateClassPair(super, cls->data()->className, 0);
	
	const class_ro_t* ro = cls->data();
	const class_ro_t* roMeta = meta->data();
	
	if (ro->baseMethods)
		ConvertMethodListGen(conv, ro->baseMethods);
	if (roMeta->baseMethods)
		ConvertMethodListGen(object_getClass(id(conv)), roMeta->baseMethods);
	if (ro->ivars)
		ConvertIvarList(conv, ro->ivars);
	if (ro->baseProtocols)
		AddClassProtocols(conv, ro->baseProtocols, slide);
	if (ro->baseProperties)
	{
		ConvertProperties(ro->baseProperties, [conv](const char* name, const objc_property_attribute_t* attr, unsigned int count) { class_addProperty(conv, name, attr, count); bug_gnustepFixPropertyCount(conv); });
	}
	
	// conv->instance_size = ro->instSize;
	// conv->isa->instance_size = roMeta->instSize;
	
	objc_registerClassPair(conv);
	LOG << "ObjC class " << cls->data()->className << " now @" << conv << std::endl;
	class_getSuperclass(conv); // HACK to force the class to be resolved (gnustep-libobjc2 blows up because cls->isa->isa is a char* still otherwise when we next use it as a superclass)
	g_classPointers[cls] = conv;

	return conv;
}

void ProcessClassesNew(const struct mach_header* mh, intptr_t slide, const class_t** classes, unsigned long size)
{
	class_t **class_refs, **class_refs_end, **super_refs, **super_refs_end;
	unsigned long refsize, refsize_s;
	std::vector<const class_t*> vecClasses;
	std::set<const class_t*> setClasses;

	class_refs = reinterpret_cast<class_t**>(
		getsectdata(mh, SEG_OBJC_CLASSREFS_NEW, SECT_OBJC_CLASSREFS_NEW, &refsize)
	);
	super_refs = reinterpret_cast<class_t**>(
		getsectdata(mh, SEG_OBJC_SUPERREFS_NEW, SECT_OBJC_SUPERREFS_NEW, &refsize_s)
	);
	if (class_refs)
		class_refs_end = class_refs + refsize / sizeof(class_t*);
	
	if (super_refs)
		super_refs_end = super_refs + refsize_s / sizeof(class_t*);

	std::copy(classes, classes+size/sizeof(class_t*), std::inserter(setClasses, setClasses.begin()));

	topology_sort<const class_t>(setClasses, vecClasses,
		[&setClasses](const class_t* t) { return setClasses.count(t->superclass) ? std::set<const class_t*>{t->superclass} : std::set<const class_t*>();  }
	);

	for (const class_t* cls : vecClasses)
	{
		Class c = RegisterClass(cls, slide);

		if (class_refs)
		{
			find_and_fix(class_refs, class_refs_end, cls, c);
			find_and_fix(class_refs, class_refs_end, cls->isa, object_getClass(id(c)));
		}
		if (super_refs)
		{
			find_and_fix(super_refs, super_refs_end, cls, c);
			find_and_fix(super_refs, super_refs_end, cls->isa, object_getClass(id(c)));
		}
	}

}

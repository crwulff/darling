#include "objc_config.h"
#include "ClassRegister.h"
#include "../dyld/public.h"
#include "../util/trace.h"
#include "../util/log.h"

#ifndef OBJC_ABI_2
#	include "old/protocol.h"
#	include "old/class.h"
#	include "old/category.h"
#else
#	include "new/protocol.h"
#	include "new/class.h"
#	include "new/category.h"
#endif
#include "common/selector.h"
#include "common/cfstring.h"
#include "common/method.h"
#include <map>

// Superclass references in Mach-O don't use classref
// Neither do category class references
std::map<const void*,Class> g_classPointers;

// Deferred load calls
std::map<Class, IMP> g_realLoads;
std::list<id>        g_pendingLoads;

void RegisterNativeClass(void* cls)
{
	LOG << "Register Native Class @ " << cls << std::endl;

	class_getSuperclass(reinterpret_cast<Class>(cls)); // HACK to force the class to be resolved
	g_classPointers[cls] = reinterpret_cast<Class>(cls);
}

// Here we process Mach-O files that have been loaded before this native library
// Then we register a handler to process all images loaded in the future
__attribute__((constructor))
	void RegisterAlreadyLoadedClasses()
{
	for (uint32_t i = 0; i < _dyld_image_count(); i++)
	{
		ProcessImageLoad(i);
	}

	_dyld_register_func_for_add_image(ProcessImageLoad);
	_dyld_register_func_for_remove_image(ProcessImageUnload);
	_dyld_register_func_for_add_objc_class(RegisterNativeClass);

	//std::cout << "Done registering\n";
}

void ProcessPendingLoads(void)
{
	SEL loadSel = sel_getUid("load");
	for (auto load : g_pendingLoads)
	{
		// load method was registered on the metaclass
		auto realLoad = g_realLoads.find(object_getClass(load));
		if (realLoad != g_realLoads.end())
		{
			realLoad->second(load, loadSel);
		}
		else
		{
			std::cerr << "Real load method not found for class @" << load << std::endl;
		}
	}
	g_pendingLoads.clear();
}

void ProcessImageLoad(uint32_t image_index)
{
	const struct mach_header *mh = _dyld_get_image_header(image_index);
	intptr_t slide = _dyld_get_image_vmaddr_slide(image_index);
	unsigned long size;

	LOG << "ObjC ProcessImageLoad @" << mh << std::endl;

#ifdef OBJC_ABI_2
	ProcessProtocolsNew(mh, slide);

	ProcessClassesNew(mh, slide, SEG_OBJC_CLASSLIST_NEW, SECT_OBJC_CLASSLIST_NEW, image_index);
	ProcessClassesNew(mh, slide, SEG_OBJC_CLASSREFS_NEW, SECT_OBJC_CLASSREFS_NEW, image_index);
	ProcessClassesNew(mh, slide, SEG_OBJC_SUPERREFS_NEW, SECT_OBJC_SUPERREFS_NEW, image_index);

	ProcessCategoriesNew(mh, slide, image_index);
#else
	module_info* modinfo;
	ProcessProtocolsOld(mh, slide);

	modinfo = reinterpret_cast<module_info*>(
		getsectdata(mh, SEG_OBJC_MODINFO_OLD, SECT_OBJC_MODINFO_OLD, &size)
	);

	if (modinfo)
	{
		ProcessClassesOld(mh, slide, modinfo);
		ProcessCategoriesOld(mh, slide, modinfo);
	}
#endif

	UpdateSelectors(mh, slide);
	UpdateCFStrings(mh);

	ProcessPendingLoads();

	LOG << "ObjC ProcessImageLoad done @" << mh << std::endl;
}

void ProcessImageUnload(uint32_t image_index)
{
	// TODO
}


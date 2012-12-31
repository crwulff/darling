#ifndef COMMON_METHOD_H
#define COMMON_METHOD_H

#include <map>
#include <list>
#include <string.h>

extern std::map<Class, IMP> g_realLoads;
extern std::list<id>        g_pendingLoads;

static id loadStub(id cls, SEL)
{
	LOG << "Load deferred for class @" << cls << std::endl;
	g_pendingLoads.push_back(cls);
	return 0;
}

template<typename ListType> void ConvertMethodListGen(Class c, const ListType* list)
{
	LOG << list->count << " methods within\n";

	const bool isMeta = class_isMetaClass(c) == YES;
	
	for (size_t i = 0; i < list->count; i++)
	{
		auto* m = &list->method_list[i];

		LOG << "Method: selName: " << m->selName << "; types: " << m->types << "; impl: " << m->impl << std::endl;

		SEL sel = sel_registerTypedName_np(m->selName, m->types);
		if (strcmp(m->selName, "load") == 0)
		{
			class_addMethod(c, sel, reinterpret_cast<IMP>(loadStub), m->types);
			g_realLoads[c] = reinterpret_cast<IMP>(m->impl);
			LOG << "Real load method registered for class @" << c << std::endl;
		}
		else
		{
			class_addMethod(c, sel, reinterpret_cast<IMP>(m->impl), m->types);
		}
	}
}

#endif

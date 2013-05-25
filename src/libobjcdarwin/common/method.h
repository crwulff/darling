#ifndef COMMON_METHOD_H
#define COMMON_METHOD_H
#include <queue>
#include <cstring>

extern std::queue<std::pair<Class, IMP>> g_pendingInitClasses;

#include <string.h>
#include "../dyld/public.h"

template<typename ListType> void ConvertMethodListGen(Class c, const ListType* list, uint32_t image_index)
{
	LOG << list->count << " methods within\n";

	const bool isMeta = class_isMetaClass(c) == YES;
	
	for (size_t i = 0; i < list->count; i++)
	{
		auto* m = &list->method_list[i];
		IMP imp = reinterpret_cast<IMP>(m->impl);

		LOG << "Method: selName: " << m->selName << "; types: " << m->types << "; impl: " << m->impl << std::endl;
		std::string sym = (isMeta) ? "+" : "-";
		sym += "[";
		sym += class_getName(c);
		sym += " ";
		sym += m->selName;
		sym += "]";
		_dyld_register_method_symbol(image_index, sym.c_str(), m->impl);

		SEL sel = sel_registerTypedName_np(m->selName, m->types);
		class_addMethod(c, sel, imp, m->types);

		if (isMeta && strcmp(m->selName, "load") == 0)
			g_pendingInitClasses.push(std::make_pair<objc_class*,IMP>((Class)c, *imp));
	}
}

#endif

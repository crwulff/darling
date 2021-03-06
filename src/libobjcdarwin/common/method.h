#ifndef COMMON_METHOD_H
#define COMMON_METHOD_H
#include <queue>
#include <cstring>
#include <string>
#include <objc/runtime.h>
#include <util/debug.h>
#include <cassert>
#include "selector.h"

extern std::queue<std::pair<Class, IMP>> & getPendingInitClasses(void);

#include <string.h>
#include <libdyld/dyld_public.h>

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

		SEL sel;
		std::string selType = m->types;
		
		ConvertSelectorType(selType);
		
		sel = sel_registerTypedName_np(m->selName, selType.c_str());
		
		class_addMethod(c, sel, imp, selType.c_str());

		if (isMeta && strcmp(m->selName, "load") == 0)
			getPendingInitClasses().push(std::make_pair<objc_class*,IMP>((Class)c, *imp));
	}
}

#endif

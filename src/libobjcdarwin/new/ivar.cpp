#include "./ivar.h"
#include "../../util/log.h"

void ConvertIvarList(Class c, const ivar_list_t* list)
{
	LOG << list->count << " ivars within\n";

	for (size_t i = 0; i < list->count; i++)
	{
		auto* v = &list->ivar_list[i];

		LOG << "Ivar: name: " << v->name << "; type: " << v->type << "; offset: " << *v->offset << "; size: " << v->size << "; alignment: " << v->alignment << std::endl;
		class_addIvar(c, v->name, v->size, v->alignment, v->type);
		Ivar ivar = class_getInstanceVariable(c, v->name);
		uintptr_t newOffset = ivar_getOffset(ivar);
		if (*v->offset != newOffset)
		{
			LOG << "Ivar moved from " << *v->offset << " to " << newOffset << std::endl;
			*v->offset = newOffset;
		}
	}
}


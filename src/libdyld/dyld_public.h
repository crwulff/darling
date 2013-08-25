/*
This file is part of Darling.

Copyright (C) 2012-2013 Lubos Dolezel

Darling is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Darling is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DYLD_PUBLIC_H
#define DYLD_PUBLIC_H
#include <stdint.h>
#include "MachOMgr.h"

namespace Darling {
	class MachOObject;
}

#ifdef __cplusplus
extern "C" {
#endif

struct dyld_unwind_sections
{
	const struct mach_header* mh;
	const void* dwarf_section;
	uintptr_t dwarf_section_length;
	const void* compact_unwind_section;
	uintptr_t compact_unwind_section_length;
};

uint32_t _dyld_image_count(void);
const struct mach_header* _dyld_get_image_header(uint32_t image_index);
intptr_t _dyld_get_image_vmaddr_slide(uint32_t image_index);
const char* _dyld_get_image_name(uint32_t image_index);
void* dyld_stub_binder_fixup(Darling::MachOObject** obj, uintptr_t lazyOffset);
void _dyld_register_method_symbol(uint32_t image_index, const char* name, void* addr);
void _dyld_finalize_symbols(uint32_t image_index);

char* getsectdata(const struct mach_header* header, const char* segname, const char* sectname, unsigned long* size);

void _dyld_register_func_for_add_image(Darling::MachOMgr::LoaderHookFunc* func);
void _dyld_register_func_for_remove_image(Darling::MachOMgr::LoaderHookFunc* func);
void _dyld_register_func_for_add_objc_class(Darling::MachOMgr::ClassRegisterHookFunc* func);

void __dyld_make_delayed_module_initializer_calls();
void __dyld_mod_term_funcs();

const char* dyld_image_path_containing_address(const void* addr);
bool _dyld_find_unwind_sections(void* addr, struct dyld_unwind_sections* info);

int32_t NSVersionOfRunTimeLibrary(const char* libraryName);

int32_t NSVersionOfLinkTimeLibrary(const char* libraryName);

int _NSGetExecutablePath(char* buf, uint32_t* bufsize);

#ifdef __cplusplus
}
#endif

#endif

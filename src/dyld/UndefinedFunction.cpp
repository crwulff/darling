/*
This file is part of Darling.

Copyright (C) 2012 Lubos Dolezel

Darling is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Darling is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "UndefinedFunction.h"
#include "../libobjcdarwin/ClassRegister.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdexcept>
#include <dlfcn.h>
#include <string.h>
#include <map>
#include <set>
#include <objc/runtime.h>
#include "public.h"

extern std::set<ClassRegisterHookFunc*> g_objcClassHooks;

UndefMgr::UndefMgr(int entries)
: m_nNext(0)
{
	int ps = getpagesize();
	void* mem;
	
	int bytes = entries * sizeof(UndefinedFunction);
	bytes = (bytes + ps - 1) / ps * ps;
	
	mem = ::mmap(0, bytes, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (mem == MAP_FAILED)
		throw std::runtime_error("Failed to map pages for UndefMgr");

	m_pMem = static_cast<UndefinedFunction*>(mem);
	m_nMax = bytes / sizeof(UndefinedFunction);
	m_nBytes = bytes;
}

UndefMgr::~UndefMgr()
{
	::munmap(m_pMem, m_nBytes);
}

void* UndefMgr::generateNew(const char* name)
{
	if ((strncmp(name, "OBJC_CLASS", 10) == 0) ||
	    (strncmp(name, "OBJC_METACLASS", 14) == 0))
	{
		// Objective-C class or metaclass info
		static std::map<std::string, Class> undefClasses;
		Class classStub = nullptr;
		auto classIter = undefClasses.find(name);
		if (classIter != undefClasses.end())
		{
			classStub = classIter->second;
		}
		else
		{
			classStub = objc_allocateClassPair(nullptr, name, 0);
			objc_registerClassPair(classStub);
			for (ClassRegisterHookFunc* func : g_objcClassHooks)
			{
				func(classStub);
			}
			undefClasses[name] = classStub;
		}

		if (strncmp(name, "OBJC_CLASS", 10) == 0)
		{
			return classStub;
		}
		else
		{
			return object_getClass(reinterpret_cast<id>(classStub));
		}
	}
	else if (strncmp(name, "OBJC_IVAR", 9) == 0)
	{
		// Objective-C ivar
		typedef struct 
		{
			const char *name;
			const char *type;
			int         offset;
		} objc_ivar;

		objc_ivar *ivarStub = new objc_ivar;
		ivarStub->name = name;
		ivarStub->type = "";
		ivarStub->offset = 0;
		return ivarStub;
	}
	else
	{
		// Generate a function stub
		if (m_nNext >= m_nMax)
			throw std::runtime_error("UndefMgr buffer full");
	
		m_pMem[m_nNext].init(name);
		return &m_pMem[m_nNext++];
	}
}

void UndefinedFunction::init(const char* name)
{
	_asm1[0] = 0x48;
	_asm1[1] = 0xbf;
	pStderr = stderr;
	_asm2[0] = 0x48;
	_asm2[1] = 0xbe;
	pErrMsg = "Undefined function called: %s\n";
	_asm3[0] = 0x48;
	_asm3[1] = 0xba;
	pFuncName = name;
	_asm4[0] = 0x48;
	_asm4[1] = 0xbb;
	pFprintf = dlsym(RTLD_DEFAULT, "fprintf");
	_asm5[0] = 0x48;
	_asm5[1] = 0x31;
	_asm5[2] = 0xc0;
	_asm5[3] = 0xff;
	_asm5[4] = 0xd3;
	_asm5[5] = 0x48;
	_asm5[6] = 0x31;
	_asm5[7] = 0xc0;
	_asm5[8] = 0xc3;
}

#ifdef TEST
int main()
{
	UndefMgr* mgr = new UndefMgr;
	int (*func)() = (int(*)()) mgr->generateNew("TestFunction");
	int (*func2)() = (int(*)()) mgr->generateNew("TestFunction2");
	
	func();
	func2();
	
	delete mgr;
	return 0;
}
#endif

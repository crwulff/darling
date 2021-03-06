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

#include "binfmt_misc.h"
#include <fstream>
#include <stdexcept>
#include <unistd.h>
#include <sys/types.h>

static void checkRoot()
{
	if (getuid())
		throw std::runtime_error("You must be root for this operation");
}

void Darling::binfmtRegister(const char* loader)
{
	checkRoot();

	std::ofstream reg("/proc/sys/fs/binfmt_misc/register");
	if (!reg.is_open())
		throw std::runtime_error("Cannot register the binfmt_misc handler, is binfmt_misc kernel support loaded and mounted?");

#if defined(__x86_64__) || defined(__powerpc64__)
	reg << ":Mach-O 64bit:M::\\xcf\\xfa\\xed\\xfe::" << loader << ":\n";
#elif defined(__i386__) || defined(__powerpc__) || defined(__arm__)
	reg << ":Mach-O 32bit:M::\\xce\\xfa\\xed\\xfe::" << loader << ":\n";
#else
#	error Unuspported platform
#endif
	reg.close();

	// In multilib environments, register FAT Mach-O files with dyld64 only
#if !defined(MULTILIB)
	reg.open("/proc/sys/fs/binfmt_misc/register");
	reg << ":Mach-O Universal:M::\\xca\\xfe\\xba\\xbe::" << loader << ":\n";
	reg.close();
#elif defined(__x86_64__) || defined(__powerpc64__)
	{
		std::string universalLoader = loader;
		universalLoader.resize(universalLoader.size() - 2);
		
		reg.open("/proc/sys/fs/binfmt_misc/register");
		reg << ":Mach-O Universal:M::\\xca\\xfe\\xba\\xbe::" << universalLoader.c_str() << ":\n";
		reg.close();
	}
#endif
}

static void deregister(const char* fmt)
{
	std::ofstream dereg(std::string("/proc/sys/fs/binfmt_misc/") + fmt);
	if (dereg.is_open())
		dereg << "-1\n";
}

void Darling::binfmtDeregister()
{
	checkRoot();

	deregister("Mach-O Universal");

	if (sizeof(void*) == 8)
		deregister("Mach-O 64bit");
	else
		deregister("Mach-O 32bit");
}


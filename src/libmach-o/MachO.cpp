/*
This file is part of Darling.

Copyright (C) 2012 Lubos Dolezel
Copyright (C) 2011 Shinichiro Hamaji

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

#include "MachO.h"
#include "FatMachO.h"
#include "MachOImpl.h"
#include <cstdio>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <unistd.h>

MachO* MachO::readFile(std::string path, const char* arch, bool need_exports, bool loadAny)
{
	int fd = ::open(path.c_str(), O_RDONLY);
	if (fd < 0)
	{
		//std::cerr << path << ": " << strerror(errno) << std::endl;
		return nullptr;
	}

	size_t offset = 0, len = 0;
	std::map<std::string, fat_arch> archs;
	if (FatMachO::readFatInfo(fd, &archs))
	{
		std::map<std::string, fat_arch>::const_iterator found = archs.find(arch);
		if (found == archs.end())
		{
			if (loadAny)
			{
				found = archs.begin();
			}
			else
			{
				std::vector<std::string> varchs;
				for (auto elem : archs)
					varchs.push_back(elem.first);

				throw fat_architecture_not_supported(varchs);
			}
		}
    
		offset = found->second.offset;
		len = found->second.size;
		// LOGF("fat offset=%lu, len=%lu\n", (unsigned long)offset, (unsigned long)len);
	}

	return new MachOImpl(path.c_str(), fd, offset, len, need_exports);
}

bool MachO::isMachO(const char* path)
{
	bool is_macho = false;
	int fd = ::open(path, O_RDONLY);
	
	if (fd != -1)
	{
		uint32_t magic;
		if (::read(fd, &magic, 4) == 4)
		{
			is_macho = ( magic == MH_MAGIC_64 || magic == MH_MAGIC || magic == FAT_CIGAM || magic == FAT_MAGIC );
		}
		::close(fd);
	}
	return is_macho;
}

uint64_t MachO::relocation_base() const
{
	uint64_t addr;
	if (is64())
	{
		for (segment_command_64* seg : m_segments64)
		{
			if (seg->initprot & VM_PROT_WRITE)
			{
				addr = seg->vmaddr;
				break;
			}
		}
	}
	else
	{
		if (m_header.flags & MH_SPLIT_SEGS)
		{
			for (segment_command* seg : m_segments)
			{
				if (seg->initprot & VM_PROT_WRITE)
				{
					addr = uint64_t(seg->vmaddr) & 0xffffffff;
					break;
				}
			}
		}
		else
			addr = uint64_t(m_segments[0]->vmaddr) & 0xffffffff;
	}
	return addr;
}

const char* MachO::platform() const
{
	switch (m_header.cputype)
	{
		//case CPU_TYPE_MC680x0:
		//	return "m68k";
		case CPU_TYPE_X86:
			return "i386";
		case CPU_TYPE_X86_64:
			return "x86-64";
		case CPU_TYPE_POWERPC:
			return "ppc";
		case CPU_TYPE_POWERPC64:
			return "ppc64";
		case CPU_TYPE_ARM:
			return "arm";
		default:
			return "?";
	}
}


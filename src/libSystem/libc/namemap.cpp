#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "../util/stlutils.h"

namespace Darling
{
    typedef bool (*DlsymHookFunc)(char* symName);
    void registerDlsymHook(DlsymHookFunc func);
    void deregisterDlsymHook(DlsymHookFunc func);
};

static const char* g_directmap =
#include "namemap.lst"
;

static bool NameTranslator(char* symName);

class NameMap : public std::map<std::string,std::string> 
{
	public:
		NameMap()
		{
			std::istringstream istr(g_directmap);
			std::string line;

			while (std::getline(istr, line))
			{
				if (line.empty() || line[0] == '#')
					continue;
		
				std::vector<std::string> segs = string_explode(line, ';');
				if (segs.size() < 2)
					continue;

				if (segs[0].compare(0, 3, "32!") == 0)
				{
#ifdef __x86_64__
					continue;
#else
					segs[0] = segs[0].substr(3);
#endif
				}

				if (segs[0].compare(0, 3, "64!") == 0)
				{
#ifdef __i386__
					continue;
#else
					segs[0] = segs[0].substr(3);
#endif
				}

				// std::cout << segs[0] << " -> " << segs[1] << std::endl;
				(*this)[segs[0]] = segs[1];
			}

			Darling::registerDlsymHook(NameTranslator);
		}

		~NameMap()
		{
			Darling::deregisterDlsymHook(NameTranslator);
		}
};

static NameMap g_nameMap;

bool NameTranslator(char* symName)
{
	auto it = g_nameMap.find(symName);
	if (it != g_nameMap.end())
	{
		strcpy(symName, it->second.c_str());
		return true;
	}
	
	it = g_nameMap.find(std::string("__darwin_")+symName);
	if (it != g_nameMap.end())
	{
		strcpy(symName, it->second.c_str());
		return true;
	}
	else if (strncmp(symName, "CC_SHA", 6) == 0)
	{
		// libcrypto has these without the CC_
		strcpy(symName, symName+3);
		return true;
	}

	return false;
}


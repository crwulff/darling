#include "NativeObject.h"
#include <dlfcn.h>
#include <sstream>
#include <stdexcept>
#include "MachOMgr.h"
#include <iostream>
#include <cstdlib>
#include <link.h>

namespace Darling {

NativeObject::NativeObject(const std::string& path)
: m_path(path), m_name(path)
{
}

NativeObject::NativeObject(void* nativeRef, const std::string& name)
	: m_nativeRef(nativeRef), m_path(name), m_name(name)
{
}

void NativeObject::load()
{
	int flags = 0;

	flags |= globalExports() ? RTLD_GLOBAL : RTLD_LOCAL;
	flags |= bindAllAtLoad() ? RTLD_NOW : RTLD_LAZY;

	m_nativeRef = ::dlopen(m_path.c_str(), flags);
	if (!m_nativeRef && 0 != m_path.compare("/dev/null"))
	{
		const char* err = ::dlerror();
		std::stringstream ss;
		
		ss << "Failed to load native library: " << err;
		throw std::runtime_error(ss.str());
	}
	else
	{

		updateName();

		if (MachOMgr::instance()->printLibraries())
			std::cerr << "dyld: Loaded " << m_path << std::endl;
		
		MachOMgr::instance()->add(this);
	}
}

void NativeObject::unload()
{
	MachOMgr::instance()->remove(this);

	if (m_path.find('/') != std::string::npos)
		::dlclose(m_nativeRef);
}

void NativeObject::updateName()
{
	struct link_map* map = nullptr;
	size_t pos;

	dlinfo(m_nativeRef, RTLD_DI_LINKMAP, &map);

	if (map)
	{
		char* real = realpath(map->l_name, nullptr);
		if (real)
		{
			m_path = real;
			free(real);
		}
	}

	pos = m_path.rfind('/');
	if (pos == std::string::npos)
		m_name = m_path;
	else
		m_name = m_path.substr(pos+1);
}

void* NativeObject::getExportedSymbol(const std::string& symbolName, bool nonWeakOnly) const
{
	void* addr;
	std::string prefixed = "__darwin_" + symbolName;

	addr = ::dlsym(m_nativeRef, prefixed.c_str());
	
	if (!addr)
		addr = ::dlvsym(m_nativeRef, symbolName.c_str(), "DARLING");

	if (!addr)
		addr = ::dlsym(m_nativeRef, symbolName.c_str());

	if (addr)
	{
		// Register the native Obj-C class if that is what this symbol was 
		if ((symbolName.compare(0, 11, "_OBJC_CLASS") == 0) ||
		    (symbolName.compare(0, 15, "_OBJC_METACLASS") == 0) ||
		    (symbolName.compare(0, 10, "OBJC_CLASS") == 0) ||
		    (symbolName.compare(0, 14, "OBJC_METACLASS") == 0))
		{
			Darling::MachOMgr::instance()->registerNativeClass(addr);
		}
	}

	return addr;
}

bool NativeObject::findSymbolInfo(const void* addr, Dl_info* p) const
{
	return ::dladdr(addr, p) != 0;
}

const char* NativeObject::name() const
{
	return m_name.c_str();
}

const std::string& NativeObject::path() const
{
	return m_path;
}

} // namespace Darling



#include "DWARFProducer.h"
#include <dwarf.h>
#include <iostream>
#include "string.h"

#define NO_ELF_SYM_INDEX 0

#ifdef __x86_64__
#define DW_ARCH_FLAGS (DW_DLC_SIZE_64|DW_DLC_OFFSET_SIZE_64)
#else
#define DW_ARCH_FLAGS (DW_DLC_SIZE_32)
#endif

template <typename T>
struct reverse_range
{
	private:
		T& x_;

	public:
		reverse_range(T& x) : x_(x) {}
		auto begin(void) const -> decltype (this->x_.rbegin()) { return x_.rbegin(); }
		auto end(void) const -> decltype (this->x_.rend()) { return x_.rend(); }
};

template <typename T>
reverse_range<T> reverse_iterate(T& x) { return reverse_range<T>(x); }

DWARFProducer::DWARFProducer(ELFBlock &elf) :
	m_elf(elf)
{
	Dwarf_Error err = DW_DLE_NE;
	m_debugInfo = dwarf_producer_init_c(
		DW_DLC_WRITE|DW_ARCH_FLAGS|DW_DLC_SYMBOLIC_RELOCATIONS,
		&DWARFProducer::callback, 0, 0, reinterpret_cast<Dwarf_Ptr>(this), &err);

	if (err != DW_DLE_NE)
	{
		std::cerr << "Failed to create dwarf info (err " << err << ")" << std::endl;
	}
}

DWARFProducer::~DWARFProducer(void)
{
	dwarf_producer_finish(m_debugInfo, 0);
}

void DWARFProducer::finalize(void)
{
	convertSections();
	convertSymbols();

	Dwarf_Signed numSections = dwarf_transform_to_disk_form(m_debugInfo, 0);

	for(Dwarf_Signed section = 0; section < numSections; section++)
	{
		Dwarf_Signed sectionIndex = 0;
		Dwarf_Unsigned length = 0;
		Dwarf_Ptr bytes = dwarf_get_section_bytes(m_debugInfo, section, &sectionIndex, &length, 0);

		m_elf.appendSectionData(sectionIndex, bytes, length);
	}

	// Apply relocations
	Dwarf_Error err = DW_DLE_NE;
	Dwarf_Unsigned relocSectionsCount = 0;
	int drdVersion = 0;
	if (DW_DLV_OK != dwarf_get_relocation_info_count(m_debugInfo, &relocSectionsCount, &drdVersion, &err))
	{
		std::cerr << "Error getting relocation info count." << std::endl;
		return;
	}

	//std::cerr << "Reloc sections: " << relocSectionsCount << std::endl;

	const std::vector<ELFBlock::Section> &sections = m_elf.getSections();

	for (Dwarf_Unsigned section = 0; section < relocSectionsCount; section++)
	{
		Dwarf_Signed relocationSectionIndex = 0;
		Dwarf_Signed sectionIndex = 0;
		Dwarf_Unsigned relocationCount = 0;
		Dwarf_Relocation_Data relocationData;
		if (DW_DLV_OK != dwarf_get_relocation_info(m_debugInfo, &relocationSectionIndex,
					&sectionIndex, &relocationCount, &relocationData, &err))
		{
			std::cerr << "Error getting relocation record " << section << std::endl;
			return;
		}

		//std::cerr << "RelocSection[" << section << "] has " << relocationCount << " relocations (section name: " << sections[sectionIndex].m_name << ")" << std::endl;
		auto &sectionInfo = sections[sectionIndex];
		for (Dwarf_Unsigned reloc = 0; reloc < relocationCount; reloc++)
		{
			// All values are already absolute so just copy them over
			if (relocationData[reloc].drd_type == dwarf_drt_data_reloc)
			{
				memcpy(sectionInfo.getPointer(relocationData[reloc].drd_offset), &relocationData[reloc].drd_symbol_index,
					relocationData[reloc].drd_length);
			}
		}
	}
}

void DWARFProducer::convertSections(void)
{
	Dwarf_Error error = DW_DLE_NE;
	auto &sections = m_elf.getSections();

	Dwarf_P_Die prevDie = nullptr;
	for (auto section : sections)
	{
		//if (prevDie) { m_sectionDies.push_back(prevDie); continue; } // DEBUG

		// Pretend this section is all from the same compilation unit
		Dwarf_P_Die unitDie = dwarf_new_die(m_debugInfo, DW_TAG_compile_unit, nullptr, nullptr, nullptr, nullptr, &error);
		std::string name = m_elf.getFilename() + section.m_name;
		dwarf_add_AT_name(unitDie, const_cast<char*>(name.c_str()), &error);
		dwarf_add_AT_comp_dir(unitDie, const_cast<char*>("/"), &error);
		dwarf_add_AT_unsigned_const(m_debugInfo, unitDie, DW_AT_language, DW_LANG_ObjC, &error);
		dwarf_add_AT_targ_address(m_debugInfo, unitDie, DW_AT_low_pc, NO_ELF_SYM_INDEX, reinterpret_cast<Dwarf_Unsigned>(section.getStart()), &error);
		dwarf_add_AT_targ_address(m_debugInfo, unitDie, DW_AT_high_pc, NO_ELF_SYM_INDEX, reinterpret_cast<Dwarf_Unsigned>(section.getStart()) + section.getSize(), &error);
		if (prevDie == nullptr)
		{
			dwarf_add_die_to_debug(m_debugInfo, unitDie, nullptr);
		}
		else
		{
			dwarf_die_link(unitDie, nullptr, nullptr, prevDie, nullptr, &error);
		}
		prevDie = unitDie;
		m_sectionDies.push_back(unitDie);

		// Add a start symbol at a minimum. If there aren't any symbols at all gdb will crash.
		Dwarf_P_Die uintTypeDie = dwarf_new_die(m_debugInfo, DW_TAG_base_type, unitDie, nullptr, nullptr, nullptr, &error);
		dwarf_add_AT_unsigned_const(m_debugInfo, uintTypeDie, DW_AT_byte_size, 4, &error);
		dwarf_add_AT_unsigned_const(m_debugInfo, uintTypeDie, DW_AT_encoding, DW_ATE_unsigned, &error);
		dwarf_add_AT_name(uintTypeDie, const_cast<char*>("uint32_t"), &error);

		addVariable(unitDie, uintTypeDie, name, section.getStart());

		//dwarf_add_arange(m_debugInfo, reinterpret_cast<Dwarf_Addr>(section.getStart()), section.m_size, NO_ELF_SYM_INDEX, &error);
	}
}

Dwarf_P_Die DWARFProducer::newDie(Dwarf_P_Die parentDie, Dwarf_Tag tag)
{
	Dwarf_Error error = DW_DLE_NE;

	return dwarf_new_die(m_debugInfo, tag, parentDie, nullptr, nullptr, nullptr, &error);
}

Dwarf_P_Die DWARFProducer::addVariable(Dwarf_P_Die parentDie, Dwarf_P_Die typeDie, const std::string &name, void *addr)
{
	Dwarf_Error error = DW_DLE_NE;

	//std::cerr << "addVariable parent " << parentDie << ", type " << typeDie << ", name " << name << ", addr " << addr << std::endl;

	Dwarf_P_Expr varLocExpr = dwarf_new_expr(m_debugInfo, &error);
	dwarf_add_expr_addr_b(varLocExpr, reinterpret_cast<Dwarf_Unsigned>(addr), NO_ELF_SYM_INDEX, &error);

	Dwarf_P_Die varDie = newDie(parentDie, DW_TAG_variable);
	dwarf_add_AT_name(varDie, const_cast<char*>(name.c_str()), &error);
	dwarf_add_AT_flag(m_debugInfo, varDie, DW_AT_external, 1, &error);
	dwarf_add_AT_reference(m_debugInfo, varDie, DW_AT_type, typeDie, &error);
	dwarf_add_AT_location_expr(m_debugInfo, varDie, DW_AT_location, varLocExpr, &error);

	return varDie;
}

Dwarf_P_Die DWARFProducer::addFunction(Dwarf_P_Die parentDie, const std::string &name, void *start, uint64_t size)
{
	Dwarf_Error error = DW_DLE_NE;

	//std::cerr << "addFunction parent " << parentDie << ", name " << name << ", start " << start << ", size " << size << std::endl;

	Dwarf_P_Die funcDie = newDie(parentDie, DW_TAG_subprogram);
	dwarf_add_AT_name(funcDie, const_cast<char*>(name.c_str()), &error);
	dwarf_add_AT_flag(m_debugInfo, funcDie, DW_AT_external, 1, &error);
	dwarf_add_AT_targ_address(m_debugInfo, funcDie, DW_AT_low_pc, NO_ELF_SYM_INDEX, reinterpret_cast<Dwarf_Unsigned>(start), &error);
	dwarf_add_AT_targ_address(m_debugInfo, funcDie, DW_AT_high_pc, NO_ELF_SYM_INDEX, reinterpret_cast<Dwarf_Unsigned>(start) + size, &error);

	return funcDie;
}

void DWARFProducer::convertSymbols(void)
{
	auto &sections = m_elf.getSections();
	auto section = sections.begin();
	auto sectionDie = m_sectionDies.begin();

	auto &symbols = m_elf.getSymbols();

	// Set sizes for all symbols with an invalid size to fill up to the next symbol
	void *nextAddr = (symbols.size() > 0) ? symbols.rbegin()->second.m_addr : nullptr;
	for (auto &symbol : reverse_iterate(symbols))
	{
		if (symbol.second.m_size == INVALID_SIZE)
		{
			symbol.second.m_size = (uintptr_t)nextAddr - (uintptr_t)symbol.second.m_addr;
		}

		nextAddr = symbol.second.m_addr;
	}

	// Add debug info for all the symbols
	for (auto &symbol : symbols)
	{ [&] {
		// Find the section this symbol belongs to
		while ((symbol.second.m_addr < section->getStart()) ||
		       (symbol.second.m_addr >= (void*)((uintptr_t)section->getStart() + section->getSize())))
		{
			if (section == sections.end() || sectionDie == m_sectionDies.end())
			{
				section = sections.begin();
				sectionDie = m_sectionDies.begin();
				std::cerr << "Symbol outside of debuggable sections: " << symbol.second.m_name << " @" << symbol.second.m_addr << std::endl;
				return;
			}

			section++, sectionDie++;

			if (section == sections.end() || sectionDie == m_sectionDies.end())
			{
				section = sections.begin();
				sectionDie = m_sectionDies.begin();
				std::cerr << "Symbol outside of debuggable sections: " << symbol.second.m_name << " @" << symbol.second.m_addr << std::endl;
				return;
			}
		}

		// Add the symbols (pretend they are all functions for the moment unless we can determine better)
		addFunction(*sectionDie, symbol.second.m_name, symbol.second.m_addr, symbol.second.m_size);
	} (); }
}

int DWARFProducer::callback(
	char           *name,
	int             size,
	Dwarf_Unsigned  type,
	Dwarf_Unsigned  flags,
	Dwarf_Unsigned  link,
	Dwarf_Unsigned  info,
	Dwarf_Unsigned *sect_name_symbol_index,
	void           *user_data,
	int            *error)
{
	// Ignore relocation sections
	if (0 == strncmp(name,".rel",4))
	{
		return 0;
	}

	//std::cerr << "Creating section " << name << std::endl;

	DWARFProducer *p = reinterpret_cast<DWARFProducer*>(user_data);

	return p->m_elf.addSection(name, nullptr, 0, flags, type, false);
}

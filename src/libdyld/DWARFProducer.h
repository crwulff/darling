
#ifndef _DWARF_PRODUCER_H_
#define _DWARF_PRODUCER_H_

#include <libdwarf.h>
#include "ELFBlock.h"

class DWARFProducer
{
	public:
		DWARFProducer(ELFBlock& elf);
		~DWARFProducer(void);

		void finalize(void);

	protected:

		void convertSections(void);
		void convertSymbols(void);

		Dwarf_P_Die newDie(Dwarf_P_Die parentDie, Dwarf_Tag tag);
		Dwarf_P_Die addVariable(Dwarf_P_Die parentDie, Dwarf_P_Die typeDie, const std::string &name, void *addr);
		Dwarf_P_Die addFunction(Dwarf_P_Die parentDie, const std::string &name, void *start, uint64_t size);

		// Callback for libdwarf producer interface
		static int callback(
			char           *name,
			int             size,
			Dwarf_Unsigned  type,
			Dwarf_Unsigned  flags,
			Dwarf_Unsigned  link,
			Dwarf_Unsigned  info,
			Dwarf_Unsigned *sect_name_symbol_index,
			void           *user_data,
			int            *error);

	protected:
		ELFBlock                          &m_elf;
		Dwarf_P_Debug                      m_debugInfo;
		std::vector<Dwarf_P_Die>           m_sectionDies;
};

#endif // _DWARF_PRODUCER_H_

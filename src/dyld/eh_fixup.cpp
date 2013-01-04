
#include "eh_fixup.h"
#include <iostream>
#include <string.h>
#include "log.h"

// These are GCC internals
extern "C" void __register_frame(void*);
extern "C" void __unregister_frame(void*);

struct dwarf_cie
{
	uint32_t length;
	int32_t  CIE_id;
	uint8_t  version;
	uint8_t  augmentation[];
} __attribute__ ((packed));

struct dwarf_fde
{
	uint32_t length;
	int32_t  CIE_delta;
	uint8_t  pc_begin[];
} __attribute__ ((packed));

uint8_t* discard_leb128(uint8_t *p)
{
	uint8_t byte;
	do { byte = *p++; } while (byte & 0x80);
	return p;
}

uintptr_t* assignPersonality(uintptr_t *personalities, uintptr_t personality)
{
	//std::cerr << "Assign personality << " << (void*)personality << std::endl;
	while ((*personalities != personality) && (*personalities != 0))
	{
		personalities++;
	}

	//std::cerr << "slot @ " << personalities << " = " << (void*) *personalities << std::endl;
	*personalities = personality;
	return personalities;
}

void getCIEEncoding(struct dwarf_cie *cie, uint8_t &fde_encoding, uint8_t &lsda_encoding)
{
	uint8_t *aug = cie->augmentation;
	if (aug[0] == 'z')
	{
		uint8_t *p = aug + strlen ((const char *)aug) + 1; /* Skip the augmentation string.  */
		p = discard_leb128(p);          /* Skip code alignment.  */
		p = discard_leb128(p);          /* Skip data alignment.  */
		if (cie->version == 1)                /* Skip return address column.  */
			p++;
		else
			p = discard_leb128(p);

		aug++;
		p = discard_leb128(p);          /* Skip augmentation length.  */
		while (*aug != 0)
		{
			if (*aug == 'R')
			{
				//std::cerr << "FDE encoding " << std::hex << (uint32_t)*p << std::endl;
				fde_encoding = *p++; // FDE encoding
			}
			if (*aug == 'L')
			{
				//std::cerr << "LSDA encoding " << std::hex << (uint32_t)*p << std::endl;
				lsda_encoding = *p++; // Language specific data area
			}
			if (*aug == 'P')
			{
				uint8_t encoding = *p & 0x7f;
				p++; // encoding

				switch (encoding & 0x0f) {
					case 0xb: // sdata4
					{
						p += 4;
						break;
					}
					default:
						std::cerr << "Unsupported encoding " << (void*)encoding << std::endl;
						break;
				}

			}
			aug++;
		}
	}
}

void process_eh_frame(uintptr_t eh_start, uintptr_t eh_size, uintptr_t slide)
{
	// Move the eh data elsewhere so we can pad with an empty entry to terminate it
	// TODO: If the DWARF2_OBJECT_END_PTR_EXTENSION is enabled we could use the size and end instead
	// like darwin does instead of copying the data elsewhere.
	char *new_eh_frame = new char[eh_size + sizeof(struct dwarf_fde) + sizeof(void*)*4];
	uintptr_t delta = (uintptr_t)new_eh_frame - (eh_start + slide);
	LOG << "Original eh_frame @" << (void*)(eh_start + slide) << " -> " << (void*)new_eh_frame << " delta " << (void*)delta << std::endl;
	memcpy(new_eh_frame, reinterpret_cast<char*>(eh_start + slide), eh_size);
	char *start = new_eh_frame;
	char *end = &new_eh_frame[eh_size];
	memset(end, 0, sizeof(struct dwarf_fde));
	uintptr_t* personalities = (uintptr_t*)(end+sizeof(struct dwarf_fde));
	memset(personalities, 0, sizeof(void*)*4);

	while (start < end)
	{
		struct dwarf_fde *fde = (struct dwarf_fde*)start;
		if (fde->CIE_delta == 0)
		{
			// Look for personality pointers to update
			struct dwarf_cie *cie = (struct dwarf_cie*)start;
			uint8_t *aug = cie->augmentation;
			if (aug[0] == 'z')
			{
				uint8_t *p = aug + strlen ((const char *)aug) + 1; /* Skip the augmentation string.  */
				p = discard_leb128(p);          /* Skip code alignment.  */
				p = discard_leb128(p);          /* Skip data alignment.  */
				if (cie->version == 1)                /* Skip return address column.  */
					p++;
				else
					p = discard_leb128(p);

				aug++;
				p = discard_leb128(p);          /* Skip augmentation length.  */
				while (*aug != 0)
				{
					if (*aug == 'R') p++; // FDE encoding
					if (*aug == 'L') p++; // Language specific data area
					if (*aug == 'P')
					{
						uint8_t encoding = *p & 0x7f;
						p++; // encoding

						switch (encoding & 0x0f) {
							case 0xb: // sdata4
							{
								// Correct the relative pointers
								//std::cerr << "Personality @" << (void*)p << " " << (void*)(*(uint32_t*)p);
								uintptr_t* personality = assignPersonality(personalities, *(uintptr_t*)(eh_start + slide + ((uintptr_t)p - (uintptr_t)new_eh_frame) + *(uint32_t*)p));
								*(uint32_t*)(p) = (uintptr_t)personality - (uintptr_t)p;
								p += 4;
								//std::cerr << " -> " << (void*)(*(uint32_t*)p) << std::endl;
								break;
							}
							default:
								std::cerr << "Unsupported encoding " << (void*)encoding << std::endl;
								break;
						}

					}
					aug++;
				}
			}
		}
		else
		{
			// Correct the relative pointers
			struct dwarf_cie *cie = (struct dwarf_cie*)(start - fde->CIE_delta + sizeof(uint32_t));
			//std::cerr << "FDE CIE @" << cie << std::endl;
			uint8_t fde_encoding = 0xff, lsda_encoding = 0xff;
			getCIEEncoding(cie, fde_encoding, lsda_encoding);

			uint8_t *p = &fde->pc_begin[0];
			switch (fde_encoding)
			{
				case 0x10: // PC_Rel Abs
					//std::cerr << "FDE @" << (void*)p << " " << std::hex << *(uintptr_t*)(&fde->pc_begin[0]);
					*(uintptr_t*)(p) -= delta;
					//std::cerr << " -> " << std::hex << *(uintptr_t*)(p) << std::endl;
					p += 16;
					break;
				default:
					std::cerr << "Unsupported FDE encoding " << (void*)fde_encoding << std::endl;
					break;
			}

			switch (lsda_encoding)
			{
				case 0xff: // omit
					break;
				case 0x10: // PC_Rel Abs
					p = discard_leb128(p);
					//std::cerr << "LSDA @" << (void*)p << " " << std::hex << *(uintptr_t*)(p);
					if (*(uintptr_t*)p != 0)
					{
						*(uintptr_t*)(p) -= delta;
					}
					//std::cerr << " -> " << std::hex << *(uintptr_t*)(p) << std::endl;
					break;
				default:
					std::cerr << "Unsupported LSDA encoding " << (void*)lsda_encoding << std::endl;
					break;
			}
		}
		start += sizeof(fde->length) + fde->length;
	}
	__register_frame(reinterpret_cast<void*>(new_eh_frame));
	// TODO: hang onto the eh_frame info so we can free it later if we unload a module
}

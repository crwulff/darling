#ifndef LIBC_ARCH_H
#define LIBC_ARCH_H
#include <stdint.h>

typedef int32_t cpu_type_t;
typedef int32_t cpu_subtype_t;

struct NXArchInfo
{
	const char* name;
	cpu_type_t cputype;
	cpu_subtype_t cpusubtype;
	int byteorder;
	const char* description;
};

#ifdef __cplusplus
extern "C"
{
#endif

const NXArchInfo* NXGetAllArchInfos();
const NXArchInfo* NXGetLocalArchInfo();
const NXArchInfo* NXGetArchInfoFromName(const char *name);
const NXArchInfo* NXGetArchInfoFromCpuType(cpu_type_t cputype, cpu_subtype_t cpusubtype);
struct fat_arch* NXFindBestFatArch(cpu_type_t cputype, cpu_subtype_t cpusubtype, struct fat_arch *fat_archs, uint32_t nfat_archs);
cpu_subtype_t NXCombineCpuSubtypes(cpu_type_t cputype, cpu_subtype_t cpusubtype1, cpu_subtype_t cpusubtype2);

cpu_type_t _CSGetProcessorArchitecture(void);

#ifdef __cplusplus
}
#endif

#endif


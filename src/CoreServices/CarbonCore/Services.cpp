
#include "Services.h"
#include <stdio.h>

mach_port_t scCreateSystemService(const char *name, void *xxx)
{
	return scCreateSystemServiceVersion(name, 0, xxx);
}

mach_port_t scCreateSystemServiceVersion(const char *name, UInt32 version, void *xxx)
{
	printf("scCreateSystemServiceVersion(%s, %d, %p) - Not implemented\n", name, version, xxx);
	return 0;
}

int _CSCreateSeed(const char *str1)
{
	printf("_CSCreateSeed(%s) - Not Implemented\n", str1);
	return 0;
}

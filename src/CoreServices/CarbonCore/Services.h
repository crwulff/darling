
#include <CoreFoundation/CFBase.h>
#include <mach/port.h>

extern "C" {

extern mach_port_t scCreateSystemService(const char *name, void *xxx);
extern mach_port_t scCreateSystemServiceVersion(const char *name, UInt32 version, void *xxx);

int _CSCreateSeed(const char *str1);

}



#ifndef _EH_FIXUP_H_
#define _EH_FIXUP_H_

#include <stdint.h>
void process_eh_frame(uintptr_t eh_start, uintptr_t eh_size, uintptr_t slide);

#endif // _EH_FIXUP_H_

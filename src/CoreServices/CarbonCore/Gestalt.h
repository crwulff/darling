
#include <CoreServices/MacTypes.h>
#include "MacErrors.h"

extern "C" {

extern OSErr Gestalt(OSType    selector, SInt32 *  response);

enum {
	gestaltSystemVersion       = 'sysv',
	gestaltSystemVersionMajor  = 'sys1',
	gestaltSystemVersionMinor  = 'sys2',
	gestaltSystemVersionBugFix = 'sys3'
};

} // extern "C"


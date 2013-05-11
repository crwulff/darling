#include "Gestalt.h"
#include <stdio.h>

OSErr Gestalt(OSType    selector, SInt32 *  response)
{
	switch (selector)
	{
		case gestaltSystemVersion:
			*response = 0x1080;
			break;

		case gestaltSystemVersionMajor:
			*response = 10;
			break;

		case gestaltSystemVersionMinor:
			*response = 8;
			break;

		case gestaltSystemVersionBugFix:
			*response = 0;
			break;

		default:
			fprintf(stderr, "Gestalt(%08X '%c%c%c%c', %p) - Not implemented\n", selector,
				(char) ((selector>>24) & 0xFF),
				(char) ((selector>>16) & 0xFF),
				(char) ((selector>>8) & 0xFF),
				(char) ((selector>>0) & 0xFF),
			       	response);
			return gestaltUndefSelectorErr;
	}

	return noErr;
}

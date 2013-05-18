
#include "Files.h"
#include <stdio.h>

OSStatus FSRefMakePath(const FSRef *ref, UInt8 *path, UInt32 maxPathSize)
{
	printf("FSRefMakePath not implemented\n");
	return 0;
}

OSStatus FSPathMakeRefWithOptions(const UInt8 *path, OptionBits options, FSRef *ref, Boolean *isDirectory)
{
	printf("FSRefMakePathWithOptions not implemented\n");
	return 0;
}

OSErr FSGetCatalogInfo(const FSRef *ref, FSCatalogInfoBitmap whichInfo, FSCatalogInfo *catalogInfo, HFSUniStr255 *outName, FSSpecPtr fsSpec, FSRef *parentRef)
{
	printf("FSGetCatalogInfo not implemented\n");
	return 0;
}

int _FSGetStrippedPath(char *str1, char *str2)
{
	printf("_FSGetStrippedPath(%p, %p) - Not implemented\n", str1, str2);
	return 0;
}


#include "Folders.h"
#include <stdio.h>

OSErr FSFindFolder(FSVolumeRefNum vRefNum, OSType folderType, Boolean createFolder, FSRef *foundRef)
{
	printf("FSFindFolder(%d, %c%c%c%c, %s, %p) - Not implemented\n", vRefNum,
			(char)(folderType >> 24), 
			(char)(folderType >> 16), 
			(char)(folderType >> 8), 
			(char)(folderType >> 0), (createFolder) ? "T" : "F", foundRef);
	return 0;
}


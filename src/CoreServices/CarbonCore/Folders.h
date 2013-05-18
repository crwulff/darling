
#include <CoreFoundation/CFBase.h>
#include "Files.h"

extern "C" {

extern OSErr FSFindFolder(FSVolumeRefNum vRefNum, OSType folderType, Boolean createFolder, FSRef *foundRef);

}

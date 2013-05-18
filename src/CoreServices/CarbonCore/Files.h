
#include <CoreFoundation/CFBase.h>
#include <CoreServices/DateTimeUtils.h>
#include "TextCommon.h"
#include "MacTypes.h"

extern "C" {

#pragma pack(push, 2)

typedef struct HFSUniStr255 {
  UInt16              length;
  UniChar             unicode[255];
} HFSUniStr255;

typedef SInt16 FSVolumeRefNum;

typedef struct FSRef {
  UInt8 hidden[80]; 
} FSRef, *FSRefPtr;

typedef struct __FSFileSecurity *FSFileSecurityRef;

typedef struct FSSpec {
#if __LP64__
  UInt8               hidden[70];             /* FSSpecs are invalid for 64 bit, but defined in case they appear in shared structs*/
#else
  FSVolumeRefNum      vRefNum;
  SInt32              parID;
  StrFileName         name;                   /* a Str63 on MacOS*/
#endif
} FSSpec, *FSSpecPtr;

typedef FSSpecPtr *FSSpecHandle;
typedef FSSpecPtr  FSSpecArrayPtr;

typedef struct FSPermissionInfo {
  UInt32              userID;
  UInt32              groupID;
  UInt8               reserved1;
  UInt8               userAccess;
  UInt16              mode;
  FSFileSecurityRef   fileSec;
} FSPermissionInfo;

typedef UInt32 FSCatalogInfoBitmap;
enum {
  kFSCatInfoNone                = 0x00000000,
  kFSCatInfoTextEncoding        = 0x00000001,
  kFSCatInfoNodeFlags           = 0x00000002,
  kFSCatInfoVolume              = 0x00000004,
  kFSCatInfoParentDirID         = 0x00000008,
  kFSCatInfoNodeID              = 0x00000010,
  kFSCatInfoCreateDate          = 0x00000020,
  kFSCatInfoContentMod          = 0x00000040,
  kFSCatInfoAttrMod             = 0x00000080,
  kFSCatInfoAccessDate          = 0x00000100,
  kFSCatInfoBackupDate          = 0x00000200,
  kFSCatInfoPermissions         = 0x00000400,
  kFSCatInfoFinderInfo          = 0x00000800,
  kFSCatInfoFinderXInfo         = 0x00001000,
  kFSCatInfoValence             = 0x00002000,
  kFSCatInfoDataSizes           = 0x00004000,
  kFSCatInfoRsrcSizes           = 0x00008000,
  kFSCatInfoSharingFlags        = 0x00010000,
  kFSCatInfoUserPrivs           = 0x00020000,
  kFSCatInfoUserAccess          = 0x00080000,
  kFSCatInfoSetOwnership        = 0x00100000,
  kFSCatInfoFSFileSecurityRef   = 0x00400000,
  kFSCatInfoAllDates            = 0x000003E0,
  kFSCatInfoGettableInfo        = 0x0003FFFF,
  kFSCatInfoSettableInfo        = 0x00001FE3,
  kFSCatInfoReserved            = (int)0xFFFC0000
};

typedef struct FSCatalogInfo {
  UInt16              nodeFlags;
  FSVolumeRefNum      volume;
  UInt32              parentDirID;
  UInt32              nodeID;
  UInt8               sharingFlags;
  UInt8               userPrivileges;
  UInt8               reserved1;
  UInt8               reserved2;
  UTCDateTime         createDate;
  UTCDateTime         contentModDate;
  UTCDateTime         attributeModDate;
  UTCDateTime         accessDate;
  UTCDateTime         backupDate;
#ifdef __LP64__
  FSPermissionInfo    permissions;
#else
  UInt32              permissions[4];
#endif
  UInt8               finderInfo[16];
  UInt8               extFinderInfo[16];
  UInt64              dataLogicalSize;
  UInt64              dataPhysicalSize;
  UInt64              rsrcLogicalSize;
  UInt64              rsrcPhysicalSize;
  UInt32              valence;
  TextEncoding        textEncodingHint;
} FSCatalogInfo;


extern OSStatus FSRefMakePath(const FSRef *ref, UInt8 *path, UInt32 maxPathSize);
extern OSStatus FSPathMakeRefWithOptions(const UInt8 *path, OptionBits options, FSRef *ref, Boolean *isDirectory);
extern OSErr FSGetCatalogInfo(const FSRef *ref, FSCatalogInfoBitmap whichInfo, FSCatalogInfo *catalogInfo, HFSUniStr255 *outName, FSSpecPtr fsSpec, FSRef *parentRef);

extern int _FSGetStrippedPath(char *str1, char *str2);

#pragma pack(pop)

} // extern "C"

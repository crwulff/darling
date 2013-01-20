
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFURL.h>

CF_EXPORT const CFStringRef kUTExportedTypeDeclarationsKey;
CF_EXPORT const CFStringRef kUTImportedTypeDeclarationsKey;
CF_EXPORT const CFStringRef kUTTypeIdentifierKey;
CF_EXPORT const CFStringRef kUTTypeTagSpecificationKey;
CF_EXPORT const CFStringRef kUTTypeConformsToKey;
CF_EXPORT const CFStringRef kUTTypeDescriptionKey;
CF_EXPORT const CFStringRef kUTTypeIconFileKey;
CF_EXPORT const CFStringRef kUTTypeReferenceURLKey;
CF_EXPORT const CFStringRef kUTTypeVersionKey;
CF_EXPORT const CFStringRef kUTTagClassFilenameExtension;
CF_EXPORT const CFStringRef kUTTagClassMIMEType;
CF_EXPORT const CFStringRef kUTTagClassNSPboardType;
CF_EXPORT const CFStringRef kUTTagClassOSType;

CF_EXPORT CFStringRef
UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass,
				      CFStringRef inTag,
				      CFStringRef inConformingToUTI);

CF_EXPORT CFArrayRef
UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass,
				 CFStringRef inTag,
				 CFStringRef inConformingToUTI);

CF_EXPORT CFStringRef
UTTypeCopyPreferredTagWithClass(CFStringRef inUTI,
				CFStringRef inTagClass);

CF_EXPORT Boolean
UTTypeEqual(CFStringRef inUTI1,
	    CFStringRef inUTI2);

CF_EXPORT Boolean
UTTypeConformsTo(CFStringRef inUTI,
		 CFStringRef inConformsToUTI);

CF_EXPORT CFStringRef
UTTypeCopyDescription(CFStringRef inUTI);

CF_EXPORT CFDictionaryRef
UTTypeCopyDeclaration(CFStringRef inUTI);

CF_EXPORT CFURLRef
UTTypeCopyDeclaringBundleURL(CFStringRef inUTI);

CF_EXPORT CFStringRef
UTCreateStringForOSType(OSType inOSType);

CF_EXPORT OSType
UTGetOSTypeFromString(CFStringRef inString);

// Undocumented
CF_EXPORT const CFStringRef kUTTagClassDeviceModelCode;

CF_EXPORT CFArrayRef
UTTypeCopyChildIdentifiers(CFStringRef inUTI);

CF_EXPORT CFArrayRef
UTTypeCopyParentIdentifiers(CFStringRef inUTI);

CF_EXPORT void
UTTypeShow(CFStringRef inUTI);

CF_EXPORT CFArrayRef
_UTCopyDeclaredTypeIdentifiers(void);

CF_EXPORT CFArrayRef
_UTTypeCopyAllTagsWithClass(CFStringRef inUTI, CFStringRef inTagClass);

CF_EXPORT CFDictionaryRef
_UTTypeCopyDescriptionLocalizationDictionary(CFStringRef inUTI);

CF_EXPORT CFArrayRef
_UTTypeCopyDynamicIdentifiersForTags(CFStringRef inUTI);

CF_EXPORT CFStringRef
_UTTypeCopyIconFileName(CFStringRef inUTI);

CF_EXPORT CFArrayRef
_UTTypeCopyPedigree(CFStringRef inUTI);

typedef enum
{
	eUTTypeInvalid = -1,
	eUTTypeNormal  = 0,
	eUTTypeActive  = 1,
	eUTTypeDynamic = 2
} EUTTypeStatus;

CF_EXPORT EUTTypeStatus
_UTTypeGetStatus(CFStringRef inUTI);

CF_EXPORT CFHashCode
_UTTypeHash(CFStringRef inUTI);


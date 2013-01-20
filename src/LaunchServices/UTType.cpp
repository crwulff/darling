
#include "UTType.h"
#include "../util/log.h"

// Helpers
class LSContext
{
	// TODO
};

Boolean
_LSContextInit(LSContext *context)
{
	// TODO
	return true;
}

void
_LSContextDestroy(LSContext *context)
{
	// TODO
}

// Type strings
const CFStringRef kUTExportedTypeDeclarationsKey = CFSTR("UTExportedTypeDeclarations");
const CFStringRef kUTImportedTypeDeclarationsKey = CFSTR("UTImportedTypeDeclarations");
const CFStringRef kUTTypeIdentifierKey           = CFSTR("UTTypeIdentifier");
const CFStringRef kUTTypeTagSpecificationKey     = CFSTR("UTTypeTagSpecification");
const CFStringRef kUTTypeConformsToKey           = CFSTR("UTTypeConformsTo");
const CFStringRef kUTTypeDescriptionKey          = CFSTR("UTTypeDescription");
const CFStringRef kUTTypeIconFileKey             = CFSTR("UTTypeIconFile");
const CFStringRef kUTTypeReferenceURLKey         = CFSTR("UTTypeReferenceURL");
const CFStringRef kUTTypeVersionKey              = CFSTR("UTTypeVersion");
const CFStringRef kUTTagClassFilenameExtension   = CFSTR("public.filename-extension");
const CFStringRef kUTTagClassMIMEType            = CFSTR("public.mime-type");
const CFStringRef kUTTagClassNSPboardType        = CFSTR("com.apple.nspboard-type");
const CFStringRef kUTTagClassOSType              = CFSTR("com.apple.ostype");

CFStringRef
UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass,
				      CFStringRef inTag,
				      CFStringRef inConformingToUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFArrayRef
UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass,
				 CFStringRef inTag,
				 CFStringRef inConformingToUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFStringRef
UTTypeCopyPreferredTagWithClass(CFStringRef inUTI,
				CFStringRef inTagClass)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

Boolean
UTTypeEqual(CFStringRef inUTI1,
	    CFStringRef inUTI2)
{
	return (kCFCompareEqualTo == CFStringCompare(inUTI1, inUTI2, kCFCompareCaseInsensitive));
}

Boolean
UTTypeConformsTo(CFStringRef inUTI,
		 CFStringRef inConformsToUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return false;
}

CFStringRef
UTTypeCopyDescription(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return CFStringCreateCopy(nullptr, inUTI);
}

CFDictionaryRef
UTTypeCopyDeclaration(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFURLRef
UTTypeCopyDeclaringBundleURL(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFStringRef
UTCreateStringForOSType(OSType inOSType)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

OSType
UTGetOSTypeFromString(CFStringRef inString)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return 'xxxx';
}

// Undocumented
const CFStringRef kUTTagClassDeviceModelCode     = CFSTR("com.apple.device-model-code");

CFArrayRef
UTTypeCopyChildIdentifiers(CFStringRef inUTI)
{
	CFArrayRef result = nullptr;
	LSContext context;
	if (_LSContextInit(&context))
	{
		result = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);

		// TODO
		LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;

		_LSContextDestroy(&context);
	}
	return result;
}

CFArrayRef
UTTypeCopyParentIdentifiers(CFStringRef inUTI)
{
	CFArrayRef result = nullptr;
	LSContext context;
	if (_LSContextInit(&context))
	{
		result = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);

		// TODO
		LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;

		_LSContextDestroy(&context);
	}
	return result;
}

void
UTTypeShow(CFStringRef inUTI)
{
	CFShow(inUTI);
}

CFArrayRef
_UTCopyDeclaredTypeIdentifiers(void)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFArrayRef
_UTTypeCopyAllTagsWithClass(CFStringRef inUTI, CFStringRef inTagClass)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFDictionaryRef
_UTTypeCopyDescriptionLocalizationDictionary(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFArrayRef
_UTTypeCopyDynamicIdentifiersForTags(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFStringRef
_UTTypeCopyIconFileName(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

CFArrayRef
_UTTypeCopyPedigree(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return nullptr;
}

Boolean
_UTTypeIdentifierIsValid(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return true;
}

Boolean
_UTTypeIdentifierIsDynamic(CFStringRef inUTI)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return false;
}

Boolean
_UTGetActiveTypeForCFStringIdentifier(LSContext *context, CFStringRef inUTI, void* xxx)
{
	// TODO
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return false;
}

EUTTypeStatus
_UTTypeGetStatusUsingDB(LSContext *context, CFStringRef inUTI)
{
	if (!_UTTypeIdentifierIsValid(inUTI)) return eUTTypeInvalid;
	if (_UTTypeIdentifierIsDynamic(inUTI)) return eUTTypeDynamic;
	if (_UTGetActiveTypeForCFStringIdentifier(context, inUTI, nullptr)) return eUTTypeActive;
	return eUTTypeNormal;
}

EUTTypeStatus
_UTTypeGetStatus(CFStringRef inUTI)
{
	EUTTypeStatus status = eUTTypeNormal;
	LSContext context;
	if (_LSContextInit(&context))
	{
		status = _UTTypeGetStatusUsingDB(&context, inUTI);
		_LSContextDestroy(&context);
	}

	return status;
}

CFHashCode
_UTTypeHash(CFStringRef inUTI)
{
	// TODO
	//return XCFStringHashCaseInsensitive(inUTI);
	LOG << "FIXME " << __FUNCTION__ << " not implemented" << std::endl;
	return 0;
}


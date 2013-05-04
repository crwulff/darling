
#include "CFConstants.h"
#include <CoreFoundation/CFURL.h>

/* CFBundle */
const CFStringRef kCFBundleInfoDictionaryVersionKey = CFSTR("CFBundleInfoDictionaryVersion");
const CFStringRef kCFBundleExecutableKey            = CFSTR("CFBundleExecutable");
const CFStringRef kCFBundleIdentifierKey            = CFSTR("CFBundleIdentifier");
const CFStringRef kCFBundleVersionKey               = CFSTR("CFBundleVersion");
const CFStringRef kCFBundleDevelopmentRegionKey     = CFSTR("CFBundleDevelopmentVersion");
const CFStringRef kCFBundleNameKey                  = CFSTR("CFBundleName");
const CFStringRef kCFBundleLocalizationsKey         = CFSTR("CFBundleLocalizations");

/* CFBundle Private? */

const CFStringRef _kCFBundleDisplayNameKey        = CFSTR("CFBundleDisplayName");
const CFStringRef _kCFBundleGetInfoStringKey      = CFSTR("CFBundleGetInfoString");
const CFStringRef _kCFBundleIconFileKey           = CFSTR("CFBundleIconFile");
const CFStringRef _kCFBundlePackageTypeKey        = CFSTR("CFBundlePackageType");
const CFStringRef _kCFBundleShortVersionStringKey = CFSTR("CFBundleShortVersionString");
const CFStringRef _kCFBundleSignatureKey          = CFSTR("CFBundleSignature");
const CFStringRef _kCFBundleDocumentTypesKey      = CFSTR("CFBundleDocumentTypes");
const CFStringRef _kCFBundleOldExecutableKey      = CFSTR("CFBundleOldExecutable");
const CFStringRef _kCFBundleTypeExtensionsKey     = CFSTR("CFBundleTypeExtensions");
const CFStringRef _kCFBundleTypeIconFileKey       = CFSTR("CFBundleTypeIconFile");
const CFStringRef _kCFBundleTypeNameKey           = CFSTR("CFBundleTypeName");
const CFStringRef _kCFBundleTypeOSTypesKey        = CFSTR("CFBundleTypeOSTypes");
const CFStringRef _kCFBundleTypeRoleKey           = CFSTR("CFBundleTypeRole");
const CFStringRef _kCFBundleURLIconFileKey        = CFSTR("CFBundleURLIconFile");
const CFStringRef _kCFBundleURLNameKey            = CFSTR("CFBundleURLName");
const CFStringRef _kCFBundleURLSchemesKey         = CFSTR("CFBundleURLSchemes");
const CFStringRef _kCFBundleURLTypesKey           = CFSTR("CFBundleURLTypes");


#if 0
/* CFError.h */
const CFStringRef kCFErrorLocalizedDescriptionKey        = CFSTR("CFErrorLocalizedDescription");
const CFStringRef kCFErrorLocalizedFailureReasonKey      = CFSTR("CFErrorLocalizedFailureReason");
const CFStringRef kCFErrorLocalizedRecoverySuggestionKey = CFSTR("CFErrorLocalizedRecoverySuggestion");
const CFStringRef kCFErrorDescriptionKey                 = CFSTR("CFErrorDescription");
const CFStringRef kCFErrorUnderlyingErrorKey             = CFSTR("CFErrorUnderlyingError");
#endif
const CFStringRef kCFErrorURLKey                         = CFSTR("CFErrorURL");
const CFStringRef kCFErrorFilePathKey                    = CFSTR("CFErrorFilePath");


/* CFPreferences.h */
const CFStringRef kCFPreferencesAnyApplication     = CFSTR("CFPreferencesAnyApplication");
const CFStringRef kCFPreferencesCurrentApplication = CFSTR("CFPreferencesCurrentApplication");
const CFStringRef kCFPreferencesAnyHost            = CFSTR("CFPreferencesAnyHost");
const CFStringRef kCFPreferencesCurrentHost        = CFSTR("CFPreferencesCurrentHost");
const CFStringRef kCFPreferencesAnyUser            = CFSTR("CFPreferencesAnyUser");
const CFStringRef kCFPreferencesCurrentUser        = CFSTR("CFPreferencesCurrentUser");

/* CFPreferences Private? */
const CFStringRef kCFManagedPreferencesMCXObjectName             = CFSTR("CFManagedPreferencesMCXObjectName");
const CFStringRef kCFManagedPreferencesMCXNotificationName       = CFSTR("CFManagedPreferencesMCXNotificationName");
const CFStringRef kCFPreferencesDidChangeNotificationName        = CFSTR("CFPreferencesDidChangeNotificationName");
const CFStringRef kCFPreferencesWebServicesProviderTypeMap       = CFSTR("CFPreferencesWebServicesProviderTypeMap");
const CFStringRef kCFPreferencesWebServicesProviderTypeWebSearch = CFSTR("CFPreferencesWebServicesProviderTypeWebSearch");
const CFStringRef kCFPreferencesDidChangeObject                  = CFSTR("CFPreferencesDidChangeObject");

/* CFURL Private? */
const CFStringRef _kCFURLApplicationHighResolutionModeIsMagnifiedKey       = CFSTR("NSURLApplicationHighResolutionModeIsMagnifiedKey");
const CFStringRef kCFURLBookmarkOriginalPathKey                            = CFSTR("NSURLBookmarkOriginalPathKey");
const CFStringRef _kCFURLCanSetApplicationHighResolutionModeIsMagnifiedKey = CFSTR("NSURLCanSetApplicationHighResolutionModeIsMagnifiedKey");
const CFStringRef _kCFURLCanSetHiddenExtensionKey                          = CFSTR("NSURLCanSetHiddenExtensionKey");
const CFStringRef _kCFURLFileAllocatedSizeOfResourceForkKey                = CFSTR("NSURLFileAllocatedSizeOfResourceForkKey");
const CFStringRef _kCFURLFileIDKey                                         = CFSTR("NSURLFileIDKey");
const CFStringRef _kCFURLFileSecurityKey                                   = CFSTR("NSURLFileSecurityKey");
const CFStringRef _kCFURLFileSizeOfResourceForkKey                         = CFSTR("NSURLFileSizeOfResourceForkKey");
const CFStringRef _kCFURLFinderInfoKey                                     = CFSTR("NSURLFinderInfoKey");
const CFStringRef _kCFURLIsApplicationKey                                  = CFSTR("NSURLIsApplicationKey");
const CFStringRef _kCFURLIsCompressedKey                                   = CFSTR("NSURLIsCompressedKey");
const CFStringRef _kCFURLIsExecutableKey                                   = CFSTR("NSURLIsExecutableKey");
const CFStringRef _kCFURLIsReadableKey                                     = CFSTR("NSURLIsReadableKey");
const CFStringRef _kCFURLIsWriteableKey                                    = CFSTR("NSURLIsWriteableKey");
const CFStringRef _kCFURLParentDirectoryIsVolumeRootKey                    = CFSTR("NSURLParentDirectoryIsVolumeRootKey");
const CFStringRef _kCFURLVolumeIsLocalKey                                  = CFSTR("NSURLVolumeIsLocalKey");
const CFStringRef _kCFURLVolumeIsQuarantinedKey                            = CFSTR("NSURLVolumeIsQuarantinedKey");
const CFStringRef _kCFURLVolumeRefNumKey                                   = CFSTR("NSURLVolumeRefNumKey");
const CFStringRef _kCFURLApplicationCategoriesKey                          = CFSTR("NSURLApplicationCategories");
const CFStringRef _kCFURLBundleIdentifierKey                               = CFSTR("NSURLBundleIdentifier");
const CFStringRef _kCFURLDistinctLocalizedNameKey                          = CFSTR("NSURLDistinctLocalizedName");
const CFStringRef _kCFURLEffectiveIconFlattenedReferenceDataKey            = CFSTR("NSURLEffectiveIconFlattenedReferenceData");
const CFStringRef _kCFURLEffectiveIconImageDataKey                         = CFSTR("NSURLEffectiveIconImageData");
const CFStringRef _kCFURLLocalizedNameDictionaryKey                        = CFSTR("NSURLLocalizedNameDictionary");
const CFStringRef _kCFURLLocalizedTypeDescriptionDictionaryKey             = CFSTR("NSURLLocalizedTypeDescriptionDictionary");
const CFStringRef _kCFURLPathKey                                           = CFSTR("NSURLPath");
const CFStringRef _kCFURLVolumeIsDiskImageKey                              = CFSTR("NSURLVolumeIsDiskImage");

/* ? */
const CFStringRef kCFPasteboardGeneral                        = CFSTR("CFPasteboardGeneral");
const CFStringRef kCFLocaleCurrentLocaleDidChangeNotification = CFSTR("CFLocaleCurrentLocaleDidChangeNotification");

/* CFSocketStream.h */
const CFStringRef kCFStreamErrorDomainSOCKS         = CFSTR("CFStreamErrorDomainSOCKS");
const CFStringRef kCFStreamErrorDomainSSL           = CFSTR("CFStreamErrorDomainSSL");
const CFStringRef kCFStreamPropertySOCKSPassword    = CFSTR("CFStreamPropertySOCKSPassword");
const CFStringRef kCFStreamPropertySOCKSProxyHost   = CFSTR("CFStreamPropertySOCKSProxyHost");
const CFStringRef kCFStreamPropertySOCKSProxyPort   = CFSTR("CFStreamPropertySOCKSProxyPort");
const CFStringRef kCFStreamPropertySOCKSUser        = CFSTR("CFStreamPropertySOCKSUser");
const CFStringRef kCFStreamPropertySOCKSVersion     = CFSTR("CFStreamPropertySOCKSVersion");
const CFStringRef kCFStreamSocketSecurityLevelSSLv3 = CFSTR("CFStreamSocketSecurityLevelSSLv3");
const CFStringRef kCFStreamSocketSOCKSVersion4      = CFSTR("CFStreamSocketSOCKSVersion4");
const CFStringRef kCFStreamSocketSOCKSVersion5      = CFSTR("CFStreamSocketSOCKSVersion5");

/* CFSocketStream private? */
const CFStringRef kCFStreamPropertyShouldCloseNativeSocket  = CFSTR("CFStreamPropertyShouldCloseNativeSocket");
const CFStringRef kCFStreamPropertySocketSSLContext         = CFSTR("CFStreamPropertySocketSSLContext");
const CFStringRef kCFStreamPropertySOCKSProxy               = CFSTR("CFStreamPropertySOCKSProxy");
const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL = CFSTR("CFStreamSocketSecurityLevelNegotiatedSSL");

/* CFUtilities.h */
const CFStringRef _kCFSystemVersionBuildVersionKey              = CFSTR("CFSystemVersionBuildVersion");
const CFStringRef _kCFSystemVersionProductNameKey               = CFSTR("CFSystemVersionProductName");
const CFStringRef _kCFSystemVersionProductUserVisibleVersionKey = CFSTR("CFSystemVersionProductUserVisibleVersion");
const CFStringRef _kCFSystemVersionProductVersionKey            = CFSTR("CFSystemVersionProductVersion");

/* CFUserNotification.h */
const CFStringRef kCFUserNotificationAlertHeaderKey          = CFSTR("CFUserNotificationAlertHeader");
const CFStringRef kCFUserNotificationAlertMessageKey         = CFSTR("CFUserNotificationAlertMessage");
const CFStringRef kCFUserNotificationAlternateButtonTitleKey = CFSTR("CFUserNotificationAlternateButtonTitle");
const CFStringRef kCFUserNotificationCheckBoxTitlesKey       = CFSTR("CFUserNotificationCheckBoxTitles");
const CFStringRef kCFUserNotificationDefaultButtonTitleKey   = CFSTR("CFUserNotificationDefaultButtonTitle");
const CFStringRef kCFUserNotificationIconURLKey              = CFSTR("CFUserNotificationIconURL");
const CFStringRef kCFUserNotificationOtherButtonTitleKey     = CFSTR("CFUserNotificationOtherButtonTitle");
const CFStringRef kCFUserNotificationTextFieldTitlesKey      = CFSTR("CFUserNotificationTextFieldTitles");
const CFStringRef kCFUserNotificationTextFieldValuesKey      = CFSTR("CFUserNotificationTextFieldValues");

/* WebServices? */
const CFStringRef kCFWebServicesProviderDefaultDisplayNameKey = CFSTR("CFWebServicesProviderDefaultDisplayName");
const CFStringRef kCFWebServicesTypeWebSearch                 = CFSTR("CFWebServicesTypeWebSearch");
const CFStringRef kCFWebServicesProviderIdentifierKey         = CFSTR("CFWebServicesProviderIdentifier");

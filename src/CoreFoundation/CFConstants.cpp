
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

#if 0
/* CFError.h */
const CFStringRef kCFErrorLocalizedDescriptionKey        = CFSTR("CFErrorLocalizedDescription");
const CFStringRef kCFErrorLocalizedFailureReasonKey      = CFSTR("CFErrorLocalizedFailureReason");
const CFStringRef kCFErrorLocalizedRecoverySuggestionKey = CFSTR("CFErrorLocalizedRecoverySuggestion");
const CFStringRef kCFErrorDescriptionKey                 = CFSTR("CFErrorDescription");
const CFStringRef kCFErrorUnderlyingErrorKey             = CFSTR("CFErrorUnderlyingError");
#endif
const CFStringRef kCFErrorURLKey                         = CFSTR("CFErrorURL");
#if 0
const CFStringRef kCFErrorFilePathKey                    = CFSTR("CFErrorFilePath");
#endif

/* CFPreferences.h */
const CFStringRef kCFPreferencesAnyApplication     = CFSTR("CFPreferencesAnyApplication");
const CFStringRef kCFPreferencesCurrentApplication = CFSTR("CFPreferencesCurrentApplication");
const CFStringRef kCFPreferencesAnyHost            = CFSTR("CFPreferencesAnyHost");
const CFStringRef kCFPreferencesCurrentHost        = CFSTR("CFPreferencesCurrentHost");
const CFStringRef kCFPreferencesAnyUser            = CFSTR("CFPreferencesAnyUser");
const CFStringRef kCFPreferencesCurrentUser        = CFSTR("CFPreferencesCurrentUser");

/* CFPreferences Private? */
const CFStringRef kCFManagedPreferencesMCXObjectName      = CFSTR("CFManagedPreferencesMCXObjectName");
const CFStringRef kCFPreferencesDidChangeNotificationName = CFSTR("CFPreferencesDidChangeNotificationName");
const CFStringRef kCFPreferencesDidChangeObject           = CFSTR("CFPreferencesDidChangeObject");

/* CFURL Private? */
CF_EXPORT const CFStringRef _kCFURLApplicationHighResolutionModeIsMagnifiedKey       = CFSTR("NSURLApplicationHighResolutionModeIsMagnifiedKey");
CF_EXPORT const CFStringRef kCFURLBookmarkOriginalPathKey                            = CFSTR("NSURLBookmarkOriginalPathKey");
CF_EXPORT const CFStringRef _kCFURLCanSetApplicationHighResolutionModeIsMagnifiedKey = CFSTR("NSURLCanSetApplicationHighResolutionModeIsMagnifiedKey");
CF_EXPORT const CFStringRef _kCFURLCanSetHiddenExtensionKey                          = CFSTR("NSURLCanSetHiddenExtensionKey");
CF_EXPORT const CFStringRef _kCFURLFileAllocatedSizeOfResourceForkKey                = CFSTR("NSURLFileAllocatedSizeOfResourceForkKey");
CF_EXPORT const CFStringRef _kCFURLFileIDKey                                         = CFSTR("NSURLFileIDKey");
CF_EXPORT const CFStringRef _kCFURLFileSecurityKey                                   = CFSTR("NSURLFileSecurityKey");
CF_EXPORT const CFStringRef _kCFURLFileSizeOfResourceForkKey                         = CFSTR("NSURLFileSizeOfResourceForkKey");
CF_EXPORT const CFStringRef _kCFURLFinderInfoKey                                     = CFSTR("NSURLFinderInfoKey");
CF_EXPORT const CFStringRef _kCFURLIsApplicationKey                                  = CFSTR("NSURLIsApplicationKey");
CF_EXPORT const CFStringRef _kCFURLIsCompressedKey                                   = CFSTR("NSURLIsCompressedKey");
CF_EXPORT const CFStringRef _kCFURLIsExecutableKey                                   = CFSTR("NSURLIsExecutableKey");
CF_EXPORT const CFStringRef _kCFURLIsReadableKey                                     = CFSTR("NSURLIsReadableKey");
CF_EXPORT const CFStringRef _kCFURLIsWriteableKey                                    = CFSTR("NSURLIsWriteableKey");
CF_EXPORT const CFStringRef _kCFURLParentDirectoryIsVolumeRootKey                    = CFSTR("NSURLParentDirectoryIsVolumeRootKey");
CF_EXPORT const CFStringRef _kCFURLVolumeIsLocalKey                                  = CFSTR("NSURLVolumeIsLocalKey");
CF_EXPORT const CFStringRef _kCFURLVolumeIsQuarantinedKey                            = CFSTR("NSURLVolumeIsQuarantinedKey");
CF_EXPORT const CFStringRef _kCFURLVolumeRefNumKey                                   = CFSTR("NSURLVolumeRefNumKey");

/* ? */
CF_EXPORT const CFStringRef kCFPasteboardGeneral = CFSTR("CFPasteboardGeneral");

/* CFSocketStream.h */
CF_EXPORT const CFStringRef kCFStreamErrorDomainSOCKS         = CFSTR("CFStreamErrorDomainSOCKS");
CF_EXPORT const CFStringRef kCFStreamErrorDomainSSL           = CFSTR("CFStreamErrorDomainSSL");
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSPassword    = CFSTR("CFStreamPropertySOCKSPassword");
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSProxyHost   = CFSTR("CFStreamPropertySOCKSProxyHost");
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSProxyPort   = CFSTR("CFStreamPropertySOCKSProxyPort");
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSUser        = CFSTR("CFStreamPropertySOCKSUser");
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSVersion     = CFSTR("CFStreamPropertySOCKSVersion");
CF_EXPORT const CFStringRef kCFStreamSocketSecurityLevelSSLv3 = CFSTR("CFStreamSocketSecurityLevelSSLv3");
CF_EXPORT const CFStringRef kCFStreamSocketSOCKSVersion4      = CFSTR("CFStreamSocketSOCKSVersion4");
CF_EXPORT const CFStringRef kCFStreamSocketSOCKSVersion5      = CFSTR("CFStreamSocketSOCKSVersion5");

/* CFUtilities.h */
CF_EXPORT const CFStringRef _kCFSystemVersionBuildVersionKey              = CFSTR("CFSystemVersionBuildVersion");
CF_EXPORT const CFStringRef _kCFSystemVersionProductNameKey               = CFSTR("CFSystemVersionProductName");
CF_EXPORT const CFStringRef _kCFSystemVersionProductUserVisibleVersionKey = CFSTR("CFSystemVersionProductUserVisibleVersion");
CF_EXPORT const CFStringRef _kCFSystemVersionProductVersionKey            = CFSTR("CFSystemVersionProductVersion");

/* CFUserNotification.h */
CF_EXPORT const CFStringRef kCFUserNotificationAlertHeaderKey          = CFSTR("CFUserNotificationAlertHeader");
CF_EXPORT const CFStringRef kCFUserNotificationAlertMessageKey         = CFSTR("CFUserNotificationAlertMessage");
CF_EXPORT const CFStringRef kCFUserNotificationAlternateButtonTitleKey = CFSTR("CFUserNotificationAlternateButtonTitle");
CF_EXPORT const CFStringRef kCFUserNotificationCheckBoxTitlesKey       = CFSTR("CFUserNotificationCheckBoxTitles");
CF_EXPORT const CFStringRef kCFUserNotificationDefaultButtonTitleKey   = CFSTR("CFUserNotificationDefaultButtonTitle");
CF_EXPORT const CFStringRef kCFUserNotificationIconURLKey              = CFSTR("CFUserNotificationIconURL");
CF_EXPORT const CFStringRef kCFUserNotificationOtherButtonTitleKey     = CFSTR("CFUserNotificationOtherButtonTitle");
CF_EXPORT const CFStringRef kCFUserNotificationTextFieldTitlesKey      = CFSTR("CFUserNotificationTextFieldTitles");
CF_EXPORT const CFStringRef kCFUserNotificationTextFieldValuesKey      = CFSTR("CFUserNotificationTextFieldValues");

/* WebServices? */
CF_EXPORT const CFStringRef kCFWebServicesProviderDefaultDisplayNameKey = CFSTR("CFWebServicesProviderDefaultDisplayName");
CF_EXPORT const CFStringRef kCFWebServicesTypeWebSearch                 = CFSTR("CFWebServicesTypeWebSearch");

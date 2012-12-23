
#include <CoreFoundation/CFString.h>

/* Note: The "Key" constants have that stripped due to the current behavior of
   NameTranslate in libobjcdarwin. */

/* CFBundle.h */
CF_EXPORT const CFStringRef kCFBundleInfoDictionaryVersionKey;
CF_EXPORT const CFStringRef kCFBundleExecutableKey;
CF_EXPORT const CFStringRef kCFBundleIdentifierKey;
CF_EXPORT const CFStringRef kCFBundleVersionKey;
CF_EXPORT const CFStringRef kCFBundleDevelopmentRegionKey;
CF_EXPORT const CFStringRef kCFBundleNameKey;
CF_EXPORT const CFStringRef kCFBundleLocalizationsKey;

/* CFBundle Private? */
CF_EXPORT const CFStringRef _kCFBundleDisplayNameKey;
CF_EXPORT const CFStringRef _kCFBundleGetInfoStringKey;
CF_EXPORT const CFStringRef _kCFBundleIconFileKey;
CF_EXPORT const CFStringRef _kCFBundlePackageTypeKey;
CF_EXPORT const CFStringRef _kCFBundleShortVersionStringKey;
CF_EXPORT const CFStringRef _kCFBundleSignatureKey;

#if 0
/* CFError.h */
CF_EXPORT const CFStringRef kCFErrorLocalizedDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedFailureReasonKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedRecoverySuggestionKey;
CF_EXPORT const CFStringRef kCFErrorDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorUnderlyingErrorKey;
#endif
CF_EXPORT const CFStringRef kCFErrorURLKey;
#if 0
CF_EXPORT const CFStringRef kCFErrorFilePathKey;
#endif

/* CFPreferences.h */
CF_EXPORT const CFStringRef kCFPreferencesAnyApplication;
CF_EXPORT const CFStringRef kCFPreferencesCurrentApplication;
CF_EXPORT const CFStringRef kCFPreferencesAnyHost;
CF_EXPORT const CFStringRef kCFPreferencesCurrentHost;
CF_EXPORT const CFStringRef kCFPreferencesAnyUser;
CF_EXPORT const CFStringRef kCFPreferencesCurrentUser;

/* CFPreferences Private? */
CF_EXPORT const CFStringRef kCFManagedPreferencesMCXObjectName;
CF_EXPORT const CFStringRef kCFPreferencesDidChangeNotificationName;
CF_EXPORT const CFStringRef kCFPreferencesDidChangeObject;

/* CFURL Private? */
CF_EXPORT const CFStringRef _kCFURLApplicationHighResolutionModeIsMagnifiedKey;
CF_EXPORT const CFStringRef kCFURLBookmarkOriginalPathKey;
CF_EXPORT const CFStringRef _kCFURLCanSetApplicationHighResolutionModeIsMagnifiedKey;
CF_EXPORT const CFStringRef _kCFURLCanSetHiddenExtensionKey;
CF_EXPORT const CFStringRef _kCFURLFileAllocatedSizeOfResourceForkKey;
CF_EXPORT const CFStringRef _kCFURLFileIDKey;
CF_EXPORT const CFStringRef _kCFURLFileSecurityKey;
CF_EXPORT const CFStringRef _kCFURLFileSizeOfResourceForkKey;
CF_EXPORT const CFStringRef _kCFURLFinderInfoKey;
CF_EXPORT const CFStringRef _kCFURLIsApplicationKey;
CF_EXPORT const CFStringRef _kCFURLIsCompressedKey;
CF_EXPORT const CFStringRef _kCFURLIsExecutableKey;
CF_EXPORT const CFStringRef _kCFURLIsReadableKey;
CF_EXPORT const CFStringRef _kCFURLIsWriteableKey;
CF_EXPORT const CFStringRef _kCFURLParentDirectoryIsVolumeRootKey;
CF_EXPORT const CFStringRef _kCFURLVolumeIsLocalKey;
CF_EXPORT const CFStringRef _kCFURLVolumeIsQuarantinedKey;
CF_EXPORT const CFStringRef _kCFURLVolumeRefNumKey;

/* ? */
CF_EXPORT const CFStringRef kCFPasteboardGeneral;

/* CFSocketStream.h */
CF_EXPORT const CFStringRef kCFStreamErrorDomainSOCKS;
CF_EXPORT const CFStringRef kCFStreamErrorDomainSSL;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSPassword;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSProxyHost;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSProxyPort;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSUser;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSVersion;
CF_EXPORT const CFStringRef kCFStreamSocketSecurityLevelSSLv3;
CF_EXPORT const CFStringRef kCFStreamSocketSOCKSVersion4;
CF_EXPORT const CFStringRef kCFStreamSocketSOCKSVersion5;

/* CFUtilities.h */
CF_EXPORT const CFStringRef _kCFSystemVersionBuildVersionKey;
CF_EXPORT const CFStringRef _kCFSystemVersionProductNameKey;
CF_EXPORT const CFStringRef _kCFSystemVersionProductUserVisibleVersionKey;
CF_EXPORT const CFStringRef _kCFSystemVersionProductVersionKey;

/* CFUserNotification.h */
CF_EXPORT const CFStringRef kCFUserNotificationAlertHeaderKey;
CF_EXPORT const CFStringRef kCFUserNotificationAlertMessageKey;
CF_EXPORT const CFStringRef kCFUserNotificationAlternateButtonTitleKey;
CF_EXPORT const CFStringRef kCFUserNotificationCheckBoxTitlesKey;
CF_EXPORT const CFStringRef kCFUserNotificationDefaultButtonTitleKey;
CF_EXPORT const CFStringRef kCFUserNotificationIconURLKey;
CF_EXPORT const CFStringRef kCFUserNotificationOtherButtonTitleKey;
CF_EXPORT const CFStringRef kCFUserNotificationTextFieldTitlesKey;
CF_EXPORT const CFStringRef kCFUserNotificationTextFieldValuesKey;

/* WebServices? */
CF_EXPORT const CFStringRef kCFWebServicesProviderDefaultDisplayNameKey;
CF_EXPORT const CFStringRef kCFWebServicesTypeWebSearch;


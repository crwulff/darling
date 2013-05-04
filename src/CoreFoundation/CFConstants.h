
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
CF_EXPORT const CFStringRef _kCFBundleDocumentTypesKey;
CF_EXPORT const CFStringRef _kCFBundleOldExecutableKey;
CF_EXPORT const CFStringRef _kCFBundleTypeExtensionsKey;
CF_EXPORT const CFStringRef _kCFBundleTypeIconFileKey;
CF_EXPORT const CFStringRef _kCFBundleTypeNameKey;
CF_EXPORT const CFStringRef _kCFBundleTypeOSTypesKey;
CF_EXPORT const CFStringRef _kCFBundleTypeRoleKey;
CF_EXPORT const CFStringRef _kCFBundleURLIconFileKey;
CF_EXPORT const CFStringRef _kCFBundleURLNameKey;
CF_EXPORT const CFStringRef _kCFBundleURLSchemesKey;
CF_EXPORT const CFStringRef _kCFBundleURLTypesKey;

#if 0
/* CFError.h */
CF_EXPORT const CFStringRef kCFErrorLocalizedDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedFailureReasonKey;
CF_EXPORT const CFStringRef kCFErrorLocalizedRecoverySuggestionKey;
CF_EXPORT const CFStringRef kCFErrorDescriptionKey;
CF_EXPORT const CFStringRef kCFErrorUnderlyingErrorKey;
#endif
CF_EXPORT const CFStringRef kCFErrorURLKey;
CF_EXPORT const CFStringRef kCFErrorFilePathKey;

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
CF_EXPORT const CFStringRef _kCFURLApplicationCategoriesKey;
CF_EXPORT const CFStringRef _kCFURLBundleIdentifierKey;
CF_EXPORT const CFStringRef _kCFURLDistinctLocalizedNameKey;
CF_EXPORT const CFStringRef _kCFURLEffectiveIconFlattenedReferenceDataKey;
CF_EXPORT const CFStringRef _kCFURLEffectiveIconImageDataKey;
CF_EXPORT const CFStringRef _kCFURLLocalizedNameDictionaryKey;
CF_EXPORT const CFStringRef _kCFURLLocalizedTypeDescriptionDictionaryKey;
CF_EXPORT const CFStringRef _kCFURLPathKey;
CF_EXPORT const CFStringRef _kCFURLVolumeIsDiskImageKey;

/* ? */
CF_EXPORT const CFStringRef kCFPasteboardGeneral;
CF_EXPORT const CFStringRef kCFLocaleCurrentLocaleDidChangeNotification;

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

/* CFSocketStream private? */
CF_EXPORT const CFStringRef kCFStreamPropertyShouldCloseNativeSocket;
CF_EXPORT const CFStringRef kCFStreamPropertySocketSSLContext;
CF_EXPORT const CFStringRef kCFStreamPropertySOCKSProxy;
CF_EXPORT const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL;

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
CF_EXPORT const CFStringRef kCFWebServicesProviderIdentifierKey;

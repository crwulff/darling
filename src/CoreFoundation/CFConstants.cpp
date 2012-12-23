
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

/* CFURL.h - Sadly these are declared in gnustep-corebase but not defined. These should be removed if/when they are. */
CF_EXPORT const CFStringRef kCFURLNameKey                              = CFSTR("CFURLName");
CF_EXPORT const CFStringRef kCFURLLocalizedNameKey                     = CFSTR("CFURLLocalizedName");
CF_EXPORT const CFStringRef kCFURLIsRegularFileKey                     = CFSTR("CFURLIsRegularFile");
CF_EXPORT const CFStringRef kCFURLIsDirectoryKey                       = CFSTR("CFURLIsDirectory");
CF_EXPORT const CFStringRef kCFURLIsSymbolicLinkKey                    = CFSTR("CFURLIsSymbolicLink");
CF_EXPORT const CFStringRef kCFURLIsVolumeKey                          = CFSTR("CFURLIsVolume");
CF_EXPORT const CFStringRef kCFURLIsPackageKey                         = CFSTR("CFURLIsPackage");
CF_EXPORT const CFStringRef kCFURLIsSystemImmutableKey                 = CFSTR("CFURLIsSystemImmutable");
CF_EXPORT const CFStringRef kCFURLIsUserImmutableKey                   = CFSTR("CFURLIsUserImmutable");
CF_EXPORT const CFStringRef kCFURLIsHiddenKey                          = CFSTR("CFURLIsHidden");
CF_EXPORT const CFStringRef kCFURLHasHiddenExtensionKey                = CFSTR("CFURLHasHiddenExtension");
CF_EXPORT const CFStringRef kCFURLCreationDateKey                      = CFSTR("CFURLCreationDate");
CF_EXPORT const CFStringRef kCFURLContentAccessDateKey                 = CFSTR("CFURLContentAccessDate");
CF_EXPORT const CFStringRef kCFURLContentModificationDateKey           = CFSTR("CFURLContentModificationDate");
CF_EXPORT const CFStringRef kCFURLAttributeModificationDateKey         = CFSTR("CFURLAttributeModificationDate");
CF_EXPORT const CFStringRef kCFURLLinkCountKey                         = CFSTR("CFURLLinkCount");
CF_EXPORT const CFStringRef kCFURLParentDirectoryURLKey                = CFSTR("CFURLParentDirectoryURL");
CF_EXPORT const CFStringRef kCFURLVolumeURLKey                         = CFSTR("CFURLVolumeURL");
CF_EXPORT const CFStringRef kCFURLTypeIdentifierKey                    = CFSTR("CFURLTypeIdentifier");
CF_EXPORT const CFStringRef kCFURLLocalizedTypeDescriptionKey          = CFSTR("CFURLLocalizedTypeDescription");
CF_EXPORT const CFStringRef kCFURLLabelNumberKey                       = CFSTR("CFURLLabelNumber");
CF_EXPORT const CFStringRef kCFURLLabelColorKey                        = CFSTR("CFURLLabelColor");
CF_EXPORT const CFStringRef kCFURLLocalizedLabelKey                    = CFSTR("CFURLLocalizedLabel");
CF_EXPORT const CFStringRef kCFURLEffectiveIconKey                     = CFSTR("CFURLEffectiveIcon");
CF_EXPORT const CFStringRef kCFURLCustomIconKey                        = CFSTR("CFURLCustomIcon");
CF_EXPORT const CFStringRef kCFURLFileResourceIdentifierKey            = CFSTR("CFURLFileResourceIdentifier");
CF_EXPORT const CFStringRef kCFURLVolumeIdentifierKey                  = CFSTR("CFURLVolumeIdentifier");
CF_EXPORT const CFStringRef kCFURLPreferredIOBlockSizeKey              = CFSTR("CFURLPreferredIOBlockSize");
CF_EXPORT const CFStringRef kCFURLIsReadableKey                        = CFSTR("CFURLIsReadable");
CF_EXPORT const CFStringRef kCFURLIsWritableKey                        = CFSTR("CFURLIsWritable");
CF_EXPORT const CFStringRef kCFURLIsExecutableKey                      = CFSTR("CFURLIsExecutable");
CF_EXPORT const CFStringRef kCFURLFileSecurityKey                      = CFSTR("CFURLFileSecurity");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeKey                  = CFSTR("CFURLFileResourceType");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeBlockSpecial         = CFSTR("CFURLFileResourceTypeBlockSpecial");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeCharacterSpecial     = CFSTR("CFURLFileResourceTypeCharacterSpecial");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeDirectory            = CFSTR("CFURLFileResourceTypeDirectory");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeNamedPipe            = CFSTR("CFURLFileResourceTypeNamedPipe");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeRegular              = CFSTR("CFURLFileResourceTypeRegular");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeSocket               = CFSTR("CFURLFileResourceTypeSocket");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeSymbolicLink         = CFSTR("CFURLFileResourceTypeSymbolicLink");
CF_EXPORT const CFStringRef kCFURLFileResourceTypeUnknown              = CFSTR("CFURLFileResourceTypeUnknown");
CF_EXPORT const CFStringRef kCFURLFileAllocatedSizeKey                 = CFSTR("CFURLFileAllocatedSize");
CF_EXPORT const CFStringRef kCFURLFileSizeKey                          = CFSTR("CFURLFileSize");
CF_EXPORT const CFStringRef kCFURLIsAliasFileKey                       = CFSTR("CFURLIsAliasFile");
CF_EXPORT const CFStringRef kCFURLIsMountTriggerKey                    = CFSTR("CFURLIsMountTrigger");
CF_EXPORT const CFStringRef kCFURLTotalFileAllocatedSizeKey            = CFSTR("CFURLTotalFileAllocatedSize");
CF_EXPORT const CFStringRef kCFURLTotalFileSizeKey                     = CFSTR("CFURLTotalFileSize");
CF_EXPORT const CFStringRef kCFURLVolumeLocalizedFormatDescriptionKey  = CFSTR("CFURLVolumeLocalizedFormatDescription");
CF_EXPORT const CFStringRef kCFURLVolumeTotalCapacityKey               = CFSTR("CFURLVolumeTotalCapacity");
CF_EXPORT const CFStringRef kCFURLVolumeAvailableCapacityKey           = CFSTR("CFURLVolumeAvailableCapacity");
CF_EXPORT const CFStringRef kCFURLVolumeResourceCountKey               = CFSTR("CFURLVolumeResourceCount");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsPersistentIDsKey       = CFSTR("CFURLVolumeSupportsPersistentIDs");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsSymbolicLinksKey       = CFSTR("CFURLVolumeSupportsSymbolicLinks");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsHardLinksKey           = CFSTR("CFURLVolumeSupportsHardLinks");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsJournalingKey          = CFSTR("CFURLVolumeSupportsJournaling");
CF_EXPORT const CFStringRef kCFURLVolumeIsJournalingKey                = CFSTR("CFURLVolumeIsJournaling");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsSparseFilesKey         = CFSTR("CFURLVolumeSupportsSparseFiles");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsZeroRunsKey            = CFSTR("CFURLVolumeSupportsZeroRuns");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsCaseSensitiveNamesKey  = CFSTR("CFURLVolumeSupportsCaseSensitiveNames");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsCasePreservedNamesKey  = CFSTR("CFURLVolumeSupportsCasePreservedNames");
CF_EXPORT const CFStringRef kCFURLVolumeNameKey                        = CFSTR("CFURLVolumeName");
CF_EXPORT const CFStringRef kCFURLVolumeLocalizedNameKey               = CFSTR("CFURLVolumeLocalizedName");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsRootDirectoryDatesKey  = CFSTR("CFURLVolumeSupportsRootDirectoryDates");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsVolumeSizesKey         = CFSTR("CFURLVolumeSupportsVolumeSizes");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsRenamingKey            = CFSTR("CFURLVolumeSupportsRenaming");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsAdvisoryFileLockingKey = CFSTR("CFURLVolumeSupportsAdvisoryFileLocking");
CF_EXPORT const CFStringRef kCFURLVolumeSupportsExtendedSecurityKey    = CFSTR("CFURLVolumeSupportsExtendedSecurity");
CF_EXPORT const CFStringRef kCFURLVolumeIsBrowsableKey                 = CFSTR("CFURLVolumeIsBrowsable");
CF_EXPORT const CFStringRef kCFURLVolumeMaximumFileSizeKey             = CFSTR("CFURLVolumeMaximumFileSize");
CF_EXPORT const CFStringRef kCFURLVolumeIsEjectableKey                 = CFSTR("CFURLVolumeIsEjectable");
CF_EXPORT const CFStringRef kCFURLVolumeIsRemovableKey                 = CFSTR("CFURLVolumeIsRemovable");
CF_EXPORT const CFStringRef kCFURLVolumeIsInternalKey                  = CFSTR("CFURLVolumeIsInternal");
CF_EXPORT const CFStringRef kCFURLVolumeIsAutomountedKey               = CFSTR("CFURLVolumeIsAutomounted");
CF_EXPORT const CFStringRef kCFURLVolumeIsLocalKey                     = CFSTR("CFURLVolumeIsLocal");
CF_EXPORT const CFStringRef kCFURLVolumeIsReadOnlyKey                  = CFSTR("CFURLVolumeIsReadOnly");
CF_EXPORT const CFStringRef kCFURLVolumeCreationDateKey                = CFSTR("CFURLVolumeCreationDate");
CF_EXPORT const CFStringRef kCFURLVolumeURLForRemountingKey            = CFSTR("CFURLVolumeURLForRemounting");
CF_EXPORT const CFStringRef kCFURLVolumeUUIDStringKey                  = CFSTR("CFURLVolumeUUIDString");
CF_EXPORT const CFStringRef kCFURLKeysOfUnsetValuesKey                 = CFSTR("CFURLKeysOfUnsetValues");

/* CFURL Private? */
CF_EXPORT const CFStringRef _kCFURLApplicationHighResolutionModeIsMagnifiedKey       = CFSTR("CFURLApplicationHighResolutionModeIsMagnified");
CF_EXPORT const CFStringRef kCFURLBookmarkOriginalPathKey                            = CFSTR("CFURLBookmarkOriginalPath");
CF_EXPORT const CFStringRef _kCFURLCanSetApplicationHighResolutionModeIsMagnifiedKey = CFSTR("CFURLCanSetApplicationHighResolutionModeIsMagnified");
CF_EXPORT const CFStringRef _kCFURLCanSetHiddenExtensionKey                          = CFSTR("CFURLCanSetHiddenExtension");
CF_EXPORT const CFStringRef _kCFURLFileAllocatedSizeOfResourceForkKey                = CFSTR("CFURLFileAllocatedSizeOfResourceFork");
CF_EXPORT const CFStringRef _kCFURLFileIDKey                                         = CFSTR("CFURLFileID");
CF_EXPORT const CFStringRef _kCFURLFileSecurityKey                                   = CFSTR("CFURLFileSecurity");
CF_EXPORT const CFStringRef _kCFURLFileSizeOfResourceForkKey                         = CFSTR("CFURLFileSizeOfResourceFork");
CF_EXPORT const CFStringRef _kCFURLFinderInfoKey                                     = CFSTR("CFURLFinderInfo");
CF_EXPORT const CFStringRef _kCFURLIsApplicationKey                                  = CFSTR("CFURLIsApplication");
CF_EXPORT const CFStringRef _kCFURLIsCompressedKey                                   = CFSTR("CFURLIsCompressed");
CF_EXPORT const CFStringRef _kCFURLIsExecutableKey                                   = CFSTR("CFURLIsExecutable");
CF_EXPORT const CFStringRef _kCFURLIsReadableKey                                     = CFSTR("CFURLIsReadable");
CF_EXPORT const CFStringRef _kCFURLIsWriteableKey                                    = CFSTR("CFURLIsWriteable");
CF_EXPORT const CFStringRef _kCFURLParentDirectoryIsVolumeRootKey                    = CFSTR("CFURLParentDirectoryIsVolumeRoot");
CF_EXPORT const CFStringRef _kCFURLVolumeIsLocalKey                                  = CFSTR("CFURLVolumeIsLocal");
CF_EXPORT const CFStringRef _kCFURLVolumeIsQuarantinedKey                            = CFSTR("CFURLVolumeIsQuarantined");
CF_EXPORT const CFStringRef _kCFURLVolumeRefNumKey                                   = CFSTR("CFURLVolumeRefNum");

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


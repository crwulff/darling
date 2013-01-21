#include "LaunchServices.h"

const CFStringRef _kLSAddToPermittedFrontASNsArrayKey                               = CFSTR("LSAddToPermittedFrontASNsArray");
const CFStringRef _kLSAllowedToBecomeFrontmostKey                                   = CFSTR("LSAllowedToBecomeFrontmost");
const CFStringRef _kLSApplicationBackgroundOnlyTypeKey                              = CFSTR("LSApplicationBackgroundOnlyType");
const CFStringRef _kLSApplicationBackgroundPriorityKey                              = CFSTR("LSApplicationBackgroundPriority");
const CFStringRef _kLSApplicationCountKey                                           = CFSTR("LSApplicationCount");
const CFStringRef _kLSApplicationDesiresAttentionKey                                = CFSTR("LSApplicationDesiresAttention");
const CFStringRef _kLSApplicationForegroundPriorityKey                              = CFSTR("LSApplicationForegroundPriority");
const CFStringRef _kLSApplicationForegroundTypeKey                                  = CFSTR("LSApplicationForegroundType");
const CFStringRef _kLSApplicationHasRegisteredKey                                   = CFSTR("LSApplicationHasRegistered");
const CFStringRef _kLSApplicationHasSignalledItIsReadyKey                           = CFSTR("LSApplicationHasSignalledItIsReady");
const CFStringRef _kLSApplicationInformationSeedKey                                 = CFSTR("LSApplicationInformationSeed");
const CFStringRef _kLSApplicationInStoppedStateKey                                  = CFSTR("LSApplicationInStoppedState");
const CFStringRef _kLSApplicationInThrottledStateAfterLaunchKey                     = CFSTR("LSApplicationInThrottledStateAfterLaunch");
const CFStringRef _kLSApplicationIsHiddenKey                                        = CFSTR("LSApplicationIsHidden");
const CFStringRef _kLSApplicationListSeedKey                                        = CFSTR("LSApplicationListSeed");
const CFStringRef _kLSApplicationLockedInStoppedStateKey                            = CFSTR("LSApplicationLockedInStoppedState");
const CFStringRef _kLSApplicationsRecordingAppleEventsKey                           = CFSTR("LSApplicationsRecordingAppleEvents");
const CFStringRef _kLSApplicationTypeKey                                            = CFSTR("LSApplicationType");
const CFStringRef _kLSApplicationTypeToRestoreKey                                   = CFSTR("LSApplicationTypeToRestore");
const CFStringRef _kLSApplicationUIElementTypeKey                                   = CFSTR("LSApplicationUIElementType");
const CFStringRef _kLSApplicationVersionKey                                         = CFSTR("LSApplicationVersion");
const CFStringRef _kLSApplicationWasTerminatedByTALKey                              = CFSTR("LSApplicationWasTerminatedByTAL");
const CFStringRef _kLSApplicationWouldBeTerminatedByTALKey                          = CFSTR("LSApplicationWouldBeTerminatedByTAL");
const CFStringRef _kLSArchitecturei386Value                                         = CFSTR("LSArchitecturei386Value");
const CFStringRef _kLSArchitectureKey                                               = CFSTR("LSArchitecture");
const CFStringRef _kLSArchitecturePowerPC64Value                                    = CFSTR("LSArchitecturePowerPC64Value");
const CFStringRef _kLSArchitecturePowerPCValue                                      = CFSTR("LSArchitecturePowerPCValue");
const CFStringRef _kLSArchitectureUnknownValue                                      = CFSTR("LSArchitectureUnknownValue");
const CFStringRef _kLSArchitecturex86_64Value                                       = CFSTR("LSArchitecturex86_64Value");
const CFStringRef _kLSASNKey                                                        = CFSTR("LSASN");
const CFStringRef _kLSASNToBringForwardAtNextApplicationExitKey                     = CFSTR("LSASNToBringForwardAtNextApplicationExit");
const CFStringRef _kLSBackgroundPriorityKey                                         = CFSTR("LSBackgroundPriority");
const CFStringRef _kLSBackgroundPriorityOnceKey                                     = CFSTR("LSBackgroundPriorityOnce");
const CFStringRef _kLSBundleIdentifierLowerCaseKey                                  = CFSTR("LSBundleIdentifierLowerCase");
const CFStringRef _kLSBundleNameLowerCaseKey                                        = CFSTR("LSBundleNameLowerCase");
const CFStringRef _kLSBundlePathDeviceIDKey                                         = CFSTR("LSBundlePathDeviceID");
const CFStringRef _kLSBundlePathINodeKey                                            = CFSTR("LSBundlePathINode");
const CFStringRef _kLSBundlePathKey                                                 = CFSTR("LSBundlePath");
const CFStringRef _kLSBundlePathLastComponentLowerCaseKey                           = CFSTR("LSBundlePathLastComponentLowerCase");
const CFStringRef _kLSCheckInTimeKey                                                = CFSTR("LSCheckInTime");
const CFStringRef _kLSDebugLevelKey                                                 = CFSTR("LSDebugLevel");
const CFStringRef _kLSDisableAllPostLaunchBringForwardRequestsKey                   = CFSTR("LSDisableAllPostLaunchBringForwardRequests");
const CFStringRef _kLSDisplayNameKey                                                = CFSTR("LSDisplayName");
const CFStringRef _kLSDoNotBFIfFrontApplicationSeedIsChangedKey                     = CFSTR("LSDoNotBFIfFrontApplicationSeedIsChanged");
const CFStringRef _kLSDoNotBringAllWindowsForwardKey                                = CFSTR("LSDoNotBringAllWindowsForward");
const CFStringRef _kLSDoNotSetTaskPolicyAutomaticallyKey                            = CFSTR("LSDoNotSetTaskPolicyAutomatically");
const CFStringRef _kLSDontDropRootPermissionsKey                                    = CFSTR("LSDontDropRootPermissions");
const CFStringRef _kLSErrorMessageStringKey                                         = CFSTR("LSErrorMessageString");
const CFStringRef _kLSExecutableFilenameLowerCaseKey                                = CFSTR("LSExecutableFilenameLowerCase");
const CFStringRef _kLSExecutableFormatCFMKey                                        = CFSTR("LSExecutableFormatCFM");
const CFStringRef _kLSExecutableFormatKey                                           = CFSTR("LSExecutableFormat");
const CFStringRef _kLSExecutableFormatMachOKey                                      = CFSTR("LSExecutableFormatMachO");
const CFStringRef _kLSExecutableFormatPoundBangKey                                  = CFSTR("LSExecutableFormatPoundBang");
const CFStringRef _kLSExecutablePathDeviceIDKey                                     = CFSTR("LSExecutablePathDeviceID");
const CFStringRef _kLSExecutablePathINodeKey                                        = CFSTR("LSExecutablePathINode");
const CFStringRef _kLSExecutablePathKey                                             = CFSTR("LSExecutablePath");
const CFStringRef _kLSExitStatusKey                                                 = CFSTR("LSExitStatus");
const CFStringRef _kLSExpectedFrontApplicationASNKey                                = CFSTR("LSExpectedFrontApplicationASN");
const CFStringRef _kLSFileCreatorKey                                                = CFSTR("LSFileCreator");
const CFStringRef _kLSFileTypeKey                                                   = CFSTR("LSFileType");
const CFStringRef _kLSFlavorKey                                                     = CFSTR("LSFlavor");
const CFStringRef _kLSForegroundPriorityKey                                         = CFSTR("LSForegroundPriority");
const CFStringRef _kLSForegroundPriorityOnceKey                                     = CFSTR("LSForegroundPriorityOnce");
const CFStringRef _kLSFrontApplicationSeedKey                                       = CFSTR("LSFrontApplicationSeed");
const CFStringRef _kLSFrontASNKey                                                   = CFSTR("LSFrontASN");
const CFStringRef _kLSFrontReservationExistsKey                                     = CFSTR("LSFrontReservationExists");
const CFStringRef _kLSHiddenApplicationCountKey                                     = CFSTR("LSHiddenApplicationCount");
const CFStringRef _kLSKeyBeingAddedKey                                              = CFSTR("LSKeyBeingAdded");
const CFStringRef _kLSKeyBeingChangedKey                                            = CFSTR("LSKeyBeingChanged");
const CFStringRef _kLSKeyBeingRemovedKey                                            = CFSTR("LSKeyBeingRemoved");
const CFStringRef _kLSKnownLSSessionIDsKey                                          = CFSTR("LSKnownLSSessionIDs");
const CFStringRef _kLSLaunchDLabelKey                                               = CFSTR("LSLaunchDLabel");
const CFStringRef _kLSLaunchedByLaunchServicesKey                                   = CFSTR("LSLaunchedByLaunchServices");
const CFStringRef _kLSLaunchedByLaunchServicesThruForkExecKey                       = CFSTR("LSLaunchedByLaunchServicesThruForkExec");
const CFStringRef _kLSLaunchedByLaunchServicesThruLaunchDKey                        = CFSTR("LSLaunchedByLaunchServicesThruLaunchD");
const CFStringRef _kLSLaunchedByLaunchServicesThruSessionLauncherKey                = CFSTR("LSLaunchedByLaunchServicesThruSessionLauncher");
const CFStringRef _kLSLaunchedInQuarantineKey                                       = CFSTR("LSLaunchedInQuarantine");
const CFStringRef _kLSLaunchInProgressKey                                           = CFSTR("LSLaunchInProgress");
const CFStringRef _kLSLaunchModifierAdditionalEnvironmentVarsDictKey                = CFSTR("LSLaunchModifierAdditionalEnvironmentVarsDict");
const CFStringRef _kLSLaunchModifierAddPSNToArgumentListKey                         = CFSTR("LSLaunchModifierAddPSNToArgumentList");
const CFStringRef _kLSLaunchModifierArchitectures                                   = CFSTR("LSLaunchModifierArchitectures");
const CFStringRef _kLSLaunchModifierAsGIDKey                                        = CFSTR("LSLaunchModifierAsGID");
const CFStringRef _kLSLaunchModifierAsUIDKey                                        = CFSTR("LSLaunchModifierAsUID");
const CFStringRef _kLSLaunchModifierAsyncKey                                        = CFSTR("LSLaunchModifierAsync");
const CFStringRef _kLSLaunchModifierDataKey                                         = CFSTR("LSLaunchModifierData");
const CFStringRef _kLSLaunchModifierDataTypeAppleEventKey                           = CFSTR("LSLaunchModifierDataTypeAppleEvent");
const CFStringRef _kLSLaunchModifierDataTypeAppParametersKey                        = CFSTR("LSLaunchModifierDataTypeAppParameters");
const CFStringRef _kLSLaunchModifierDataTypeKey                                     = CFSTR("LSLaunchModifierDataType");
const CFStringRef _kLSLaunchModifierDoNotAddCOMMAND_MODEEnvironmentVariableKey      = CFSTR("LSLaunchModifierDoNotAddCOMMAND_MODEEnvironmentVariable");
const CFStringRef _kLSLaunchModifierDoNotMakeFrontmostWhenReadyKey                  = CFSTR("LSLaunchModifierDoNotMakeFrontmostWhenReady");
const CFStringRef _kLSLaunchModifierFailureErrorCodeKey                             = CFSTR("LSLaunchModifierFailureErrorCode");
const CFStringRef _kLSLaunchModifierFailureErrorStringKey                           = CFSTR("LSLaunchModifierFailureErrorString");
const CFStringRef _kLSLaunchModifierForce32Bit                                      = CFSTR("LSLaunchModifierForce32Bit");
const CFStringRef _kLSLaunchModifierForcePowerPC                                    = CFSTR("LSLaunchModifierForcePowerPC");
const CFStringRef _kLSLaunchModifierFullEnvironmentVarsDictKey                      = CFSTR("LSLaunchModifierFullEnvironmentVarsDict");
const CFStringRef _kLSLaunchModifierLaunchAndHideOthersKey                          = CFSTR("LSLaunchModifierLaunchAndHideOthers");
const CFStringRef _kLSLaunchModifierLaunchedHiddenKey                               = CFSTR("LSLaunchModifierLaunchedHidden");
const CFStringRef _kLSLaunchModifierLaunchInStoppedStateKey                         = CFSTR("LSLaunchModifierLaunchInStoppedState");
const CFStringRef _kLSLaunchModifierLaunchWithASLRDisabledKey                       = CFSTR("LSLaunchModifierLaunchWithASLRDisabled");
const CFStringRef _kLSLaunchModifierLeaveOpenFilesAloneKey                          = CFSTR("LSLaunchModifierLeaveOpenFilesAlone");
const CFStringRef _kLSLaunchModifierLeaveSTDERRAloneKey                             = CFSTR("LSLaunchModifierLeaveSTDERRAlone");
const CFStringRef _kLSLaunchModifierLeaveSTDINAloneKey                              = CFSTR("LSLaunchModifierLeaveSTDINAlone");
const CFStringRef _kLSLaunchModifierLeaveSTDOUTAloneKey                             = CFSTR("LSLaunchModifierLeaveSTDOUTAlone");
const CFStringRef _kLSLaunchModifierNewCopyKey                                      = CFSTR("LSLaunchModifierNewCopy");
const CFStringRef _kLSLaunchModifierRefConKey                                       = CFSTR("LSLaunchModifierRefCon");
const CFStringRef _kLSLaunchModifiersBFIfFrontSeedChangesDuringLaunchKey            = CFSTR("LSLaunchModifiersBFIfFrontSeedChangesDuringLaunch");
const CFStringRef _kLSLaunchModifiersBFIfMouseButtonIsDownDuringLaunchKey           = CFSTR("LSLaunchModifiersBFIfMouseButtonIsDownDuringLaunch");
const CFStringRef _kLSLaunchModifiersBFIfUserActivityOccursDuringLaunchKey          = CFSTR("LSLaunchModifiersBFIfUserActivityOccursDuringLaunch");
const CFStringRef _kLSLaunchModifiersFrontApplicationSeedKey                        = CFSTR("LSLaunchModifiersFrontApplicationSeed");
const CFStringRef _kLSLaunchModifiersKey                                            = CFSTR("LSLaunchModifiers");
const CFStringRef _kLSLaunchModifiersLaunchedBecauseOfPersistenceKey                = CFSTR("LSLaunchModifiersLaunchedBecauseOfPersistence");
const CFStringRef _kLSLaunchModifiersLaunchProgressTimeoutKey                       = CFSTR("LSLaunchModifiersLaunchProgressTimeout");
const CFStringRef _kLSLaunchModifiersTimeoutBeforeRestoringBackgroundPriorityKey    = CFSTR("LSLaunchModifiersTimeoutBeforeRestoringBackgroundPriority");
const CFStringRef _kLSLaunchModifierUMaskKey                                        = CFSTR("LSLaunchModifierUMask");
const CFStringRef _kLSLaunchModifierUserActivityCountAtLaunchKey                    = CFSTR("LSLaunchModifierUserActivityCountAtLaunch");
const CFStringRef _kLSLaunchModifierWithLoginKey                                    = CFSTR("LSLaunchModifierWithLogin");
const CFStringRef _kLSLaunchTimeKey                                                 = CFSTR("LSLaunchTime");
const CFStringRef _kLSMenuBarOwnerApplicationSeedKey                                = CFSTR("LSMenuBarOwnerApplicationSeed");
const CFStringRef _kLSMetaExpectedFrontAppsASNsKey                                  = CFSTR("LSMetaExpectedFrontAppsASNs");
const CFStringRef _kLSMetaInfoActiveCGSSessionIDKey                                 = CFSTR("LSMetaInfoActiveCGSSessionID");
const CFStringRef _kLSMetaInfoAddUIDsToSessionKey                                   = CFSTR("LSMetaInfoAddUIDsToSession");
const CFStringRef _kLSMetaInfoCGSSessionIDKey                                       = CFSTR("LSMetaInfoCGSSessionID");
const CFStringRef _kLSModifierLaunchedForPersistenceKey                             = CFSTR("LSModifierLaunchedForPersistence");
const CFStringRef _kLSModifierRefConKey                                             = CFSTR("LSModifierRefCon");
const CFStringRef _kLSMouseButtonDownKey                                            = CFSTR("LSMouseButtonDown");
const CFStringRef _kLSNotificationsDelayedCountKey                                  = CFSTR("LSNotificationsDelayedCount");
const CFStringRef _kLSNotificationsPendingCountKey                                  = CFSTR("LSNotificationsPendingCount");
const CFStringRef _kLSNotificationsSentCountKey                                     = CFSTR("LSNotificationsSentCount");
const CFStringRef _kLSNotifyBecameFrontmostAnotherLaunchKey                         = CFSTR("LSNotifyBecameFrontmostAnotherLaunch");
const CFStringRef _kLSNotifyBecameFrontmostFirstActivationKey                       = CFSTR("LSNotifyBecameFrontmostFirstActivation");
const CFStringRef _kLSNotifyLaunchRequestArgumentListKey                            = CFSTR("LSNotifyLaunchRequestArgumentList");
const CFStringRef _kLSNotifyLaunchRequestLaunchModifiersKey                         = CFSTR("LSNotifyLaunchRequestLaunchModifiers");
const CFStringRef _kLSOriginalExecutablePathDeviceIDKey                             = CFSTR("LSOriginalExecutablePathDeviceID");
const CFStringRef _kLSOriginalExecutablePathINodeKey                                = CFSTR("LSOriginalExecutablePathINode");
const CFStringRef _kLSOriginalExecutablePathKey                                     = CFSTR("LSOriginalExecutablePath");
const CFStringRef _kLSOriginalPIDKey                                                = CFSTR("LSOriginalPID");
const CFStringRef _kLSParentASNKey                                                  = CFSTR("LSParentASN");
const CFStringRef _kLSParentASNWasInferredKey                                       = CFSTR("LSParentASNWasInferred");
const CFStringRef _kLSPermittedFrontASNsArrayKey                                    = CFSTR("LSPermittedFrontASNsArray");
const CFStringRef _kLSPersistenceSuppressRelaunchAtLoginKey                         = CFSTR("LSPersistenceSuppressRelaunchAtLogin");
const CFStringRef _kLSPIDKey                                                        = CFSTR("LSPID");
const CFStringRef _kLSPIDsInSessionKey                                              = CFSTR("LSPIDsInSession");
const CFStringRef _kLSPreviousASNKey                                                = CFSTR("LSPreviousASN");
const CFStringRef _kLSPreviousPresentationModeKey                                   = CFSTR("LSPreviousPresentationMode");
const CFStringRef _kLSPreviousValueKey                                              = CFSTR("LSPreviousValue");
const CFStringRef _kLSPSNToBringForwardAtNextApplicationExitKey                     = CFSTR("LSPSNToBringForwardAtNextApplicationExit");
const CFStringRef _kLSRecordingAppleEventsKey                                       = CFSTR("LSRecordingAppleEvents");
const CFStringRef _kLSRemoveFromPermittedFrontASNsArrayKey                          = CFSTR("LSRemoveFromPermittedFrontASNsArray");
const CFStringRef _kLSRequiresCarbonKey                                             = CFSTR("LSRequiresCarbon");
const CFStringRef _kLSRequiresClassicKey                                            = CFSTR("LSRequiresClassic");
const CFStringRef _kLSServerMessageCountKey                                         = CFSTR("LSServerMessageCount");
const CFStringRef _kLSSessionAttributesKey                                          = CFSTR("LSSessionAttributes");
const CFStringRef _kLSSessionIDKey                                                  = CFSTR("LSSessionID");
const CFStringRef _kLSSessionLauncherASNKey                                         = CFSTR("LSSessionLauncherASN");
const CFStringRef _kLSShellExecutablePathKey                                        = CFSTR("LSShellExecutablePath");
const CFStringRef _kLSSystemProcessASNKey                                           = CFSTR("LSSystemProcessASN");
const CFStringRef _kLSUIDsInSessionKey                                              = CFSTR("LSUIDsInSession");
const CFStringRef _kLSUIPresentationModeAllHiddenValue                              = CFSTR("LSUIPresentationModeAllHiddenValue");
const CFStringRef _kLSUIPresentationModeAllSuppressedValue                          = CFSTR("LSUIPresentationModeAllSuppressedValue");
const CFStringRef _kLSUIPresentationModeContentHiddenValue                          = CFSTR("LSUIPresentationModeContentHiddenValue");
const CFStringRef _kLSUIPresentationModeContentSuppressedValue                      = CFSTR("LSUIPresentationModeContentSuppressedValue");
const CFStringRef _kLSUIPresentationModeKey                                         = CFSTR("LSUIPresentationMode");
const CFStringRef _kLSUIPresentationModeNormalValue                                 = CFSTR("LSUIPresentationModeNormalValue");
const CFStringRef _kLSUIPresentationOptionsKey                                      = CFSTR("LSUIPresentationOptions");
const CFStringRef _kLSUnhiddenApplicationCountKey                                   = CFSTR("LSUnhiddenApplicationCount");
const CFStringRef _kLSUserActivityCountKey                                          = CFSTR("LSUserActivityCount");
const CFStringRef _kLSVisibleApplicationCountKey                                    = CFSTR("LSVisibleApplicationCount");
const CFStringRef _kLSVisibleApplicationListSeedKey                                 = CFSTR("LSVisibleApplicationListSeed");
const CFStringRef _kLSWantsToComeForwardAtRegistrationTimeKey                       = CFSTR("LSWantsToComeForwardAtRegistrationTime");

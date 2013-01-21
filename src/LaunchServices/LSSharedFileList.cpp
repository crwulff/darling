
#include <LaunchServices/LSSharedFileList.h>

CFStringRef kLSSharedFileListFavoriteVolumes             = CFSTR("LSSharedFileListFavoriteVolumes");
CFStringRef kLSSharedFileListFavoriteItems               = CFSTR("LSSharedFileListFavoriteItems");
CFStringRef kLSSharedFileListRecentApplicationItems      = CFSTR("LSSharedFileListRecentApplicationItems");
CFStringRef kLSSharedFileListRecentDocumentItems         = CFSTR("LSSharedFileListRecentDocumentItems");
CFStringRef kLSSharedFileListRecentServerItems           = CFSTR("LSSharedFileListRecentServerItems");
CFStringRef kLSSharedFileListSessionLoginItems           = CFSTR("LSSharedFileListSessionLoginItems");
CFStringRef kLSSharedFileListGlobalLoginItems            = CFSTR("LSSharedFileListGlobalLoginItems");
CFStringRef kLSSharedFileListRecentItemsMaxAmount        = CFSTR("LSSharedFileListRecentItemsMaxAmount");
CFStringRef kLSSharedFileListVolumesComputerVisible      = CFSTR("LSSharedFileListVolumesComputerVisible");
CFStringRef kLSSharedFileListVolumesIDiskVisible         = CFSTR("LSSharedFileListVolumesIDiskVisible");
CFStringRef kLSSharedFileListVolumesNetworkVisible       = CFSTR("LSSharedFileListVolumesNetworkVisible");

LSSharedFileListItemRef kLSSharedFileListItemBeforeFirst = nullptr;
LSSharedFileListItemRef kLSSharedFileListItemLast        = nullptr;

CFStringRef kLSSharedFileListItemHidden                  = CFSTR("LSSharedFileListItemHidden");
CFStringRef kLSSharedFileListLoginItemHidden             = CFSTR("LSSharedFileListLoginItemHidden");

// Undocumented
const CFStringRef kLSSharedFileListItemIsComputer        = CFSTR("com.apple.LSSharedFileList.IsComputer");
const CFStringRef kLSSharedFileListItemIsEjectableVolume = CFSTR("com.apple.LSSharedFileList.IsEjectableVolume");
const CFStringRef kLSSharedFileListItemIsIDisk           = CFSTR("com.apple.LSSharedFileList.IsDisk");
const CFStringRef kLSSharedFileListItemIsMeetingRoom     = CFSTR("com.apple.LSSharedFileList.IsMeetingRoom");
const CFStringRef kLSSharedFileListItemIsNetwork         = CFSTR("com.apple.LSSharedFileList.IsNetwork");
const CFStringRef kLSSharedFileListItemIsRemoteDisc      = CFSTR("com.apple.LSSharedFileList.IsRemoteDisc");
const CFStringRef kLSSharedFileListItemLocked            = CFSTR("com.apple.LSSharedFileList.ItemIsLocked");
const CFStringRef kLSSharedFileListItemTargetIsDirectory = CFSTR("com.apple.LSSharedFileList.TargetIsDirectory");
const CFStringRef kLSSharedFileListItemTargetIsVolume    = CFSTR("com.apple.LSSharedFileList.TargetIsVolume");
const CFStringRef kLSSharedFileListItemTargetName        = CFSTR("com.apple.LSSharedFileList.TargetName");
const CFStringRef kLSSharedFileListSavedSearchesItems    = CFSTR("com.apple.LSSharedFileList.SavedSearches");
const CFStringRef kLSSharedFileListSharePoints           = CFSTR("com.apple.LSSharedFileList.SharePoints");
const CFStringRef kLSSharedFileListSpecialItemIdentifier = CFSTR("com.apple.LSSharedFileList.SpecialItemIdentifier");

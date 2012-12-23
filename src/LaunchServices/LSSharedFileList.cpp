
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

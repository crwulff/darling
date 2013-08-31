
#include <LaunchServices/LSInfo.h>

const CFStringRef kLSItemContentType            = CFSTR("LSItemContentType");
const CFStringRef kLSItemFileType               = CFSTR("LSItemFileType");
const CFStringRef kLSItemFileCreator            = CFSTR("LSItemFileCreator");
const CFStringRef kLSItemExtension              = CFSTR("LSItemExtension");
const CFStringRef kLSItemDisplayName            = CFSTR("LSItemDisplayName");
const CFStringRef kLSItemDisplayKind            = CFSTR("LSItemDisplayKind");
const CFStringRef kLSItemRoleHandlerDisplayName = CFSTR("LSItemRoleHandlerDisplayName");
const CFStringRef kLSItemIsInvisible            = CFSTR("LSItemIsInvisible");
const CFStringRef kLSItemExtensionIsHidden      = CFSTR("LSItemExtensionIsHidden");
const CFStringRef kLSItemQuarantineProperties   = CFSTR("LSItemQuarantineProperties");

OSStatus LSSetDefaultHandlerForURLScheme(CFStringRef inURLScheme, CFStringRef inHandlerBundleID)
{
  // TODO
  return 0;
}

CFArrayRef LSCopyApplicationURLsForURL(CFURLRef inURL, LSRolesMask inRoleMask)
{
  // TODO
  return NULL;
}

CFStringRef LSCopyDefaultHandlerForURLScheme(CFStringRef scheme)
{
  // TODO
  return NULL;
}

OSStatus LSRegisterURL(CFURLRef inURL, Boolean inUpdate)
{
  // TODO
  return 0;
}

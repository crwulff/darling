
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFURL.h>
#include "CoreServices/MacTypes.h"

extern "C" {

extern const CFStringRef kLSItemContentType;
extern const CFStringRef kLSItemFileType;
extern const CFStringRef kLSItemFileCreator;
extern const CFStringRef kLSItemExtension;
extern const CFStringRef kLSItemDisplayName;
extern const CFStringRef kLSItemDisplayKind;
extern const CFStringRef kLSItemRoleHandlerDisplayName;
extern const CFStringRef kLSItemIsInvisible;
extern const CFStringRef kLSItemExtensionIsHidden;
extern const CFStringRef kLSItemQuarantineProperties;

OSStatus LSSetDefaultHandlerForURLScheme(CFStringRef inURLScheme, CFStringRef inHandlerBundleID);

typedef OptionBits LSRolesMask;
enum {
  kLSRolesNone   = 0x00000001,
  kLSRolesViewer = 0x00000002,
  kLSRolesEditor = 0x00000004,
  kLSRolesShell  = 0x00000008,
  kLSRolesAll    = 0xFFFFFFFF
};

CFArrayRef LSCopyApplicationURLsForURL(CFURLRef inURL, LSRolesMask inRoleMask);

}

/*
This file is part of Darling.

Copyright (C) 2013 Chris Wulff

Darling is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Darling is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CGSHOTKEYS_H
#define CGSHOTKEYS_H

#include "CGError.h"

#include <mach/port.h>

#include <stdint.h>
#include <Foundation/NSObjCRuntime.h>

extern "C" {

typedef enum    
{
  kCGSHotKeyFocusMenubar                 = 7,
  kCGSHotKeyFocusDock                    = 8,
  kCGSHotKeyFocusNextGlobalWindow        = 9,
  kCGSHotKeyFocusToolbar                 = 10,
  kCGSHotKeyFocusFloatingWindow          = 11,
  kCGSHotKeyToggleFullKeyboardAccess     = 12,
  kCGSHotKeyFocusNextControl             = 13,
  kCGSHotKeyToggleZoom                   = 15,
  kCGSHotKeyZoomIn                       = 17,
  kCGSHotKeyZoomOut                      = 19,
  kCGSHotKeyInvertScreen                 = 21,
  kCGSHotKeyZoomToggleSmoothing          = 23,
  kCGSHotKeyIncreaseContrast             = 25,
  kCGSHotKeyDecreaseContrast             = 26,
  kCGSHotKeyFocusApplicationWindow       = 27,
  kCGSHotKeyScreenshot                   = 28,
  kCGSHotKeyScreenshotToClipboard        = 29,
  kCGSHotKeyScreenshotRegion             = 30,
  kCGSHotKeyScreenshotRegionToClipboard  = 31,
  kCGSHotKeyExposeAllWindows             = 32,
  kCGSHotKeyExposeApplicationWindows     = 33,
  kCGSHotKeyExposeAllWindowsSlow         = 34,
  kCGSHotKeyExposeApplicationWindowsSlow = 35,
  kCGSHotKeyExposeDesktop                = 36,
  kCGSHotKeyExposeDesktopsSlow           = 37,  
  kCGSHotKeyToggleCharacterPallette      = 50,
  kCGSHotKeyFocusDrawer                  = 51,
  kCGSHotKeyToggleDockAutohide           = 52,
  kCGSHotKeyDecreaseDisplayBrightness    = 53,
  kCGSHotKeyIncreaseDisplayBrightness    = 54,
  kCGSHotKeyFocusStatusItems             = 57,
  kCGSHotKeyToggleVoiceOver              = 59,
  kCGSHotKeySelectPreviousInputSource    = 60,
  kCGSHotKeySelectNextInputSource        = 61,
  kCGSHotKeyDashboard                    = 62,
  kCGSHotKeyDashboardSlow                = 63,
  kCGSHotKeySpotlightSearchField         = 64,
  kCGSHotKeySpotlightWindow              = 65,
  kCGSHotKeyLookUpWordInDictionary       = 70,
  kCGSHotKeyToggleFrontRow               = 73,
  kCGSHotKeySpaces                       = 75,
  kCGSHotKeySpacesSlow                   = 76,
  kCGSHotKeySpaceLeft                    = 79,
  kCGSHotKeySpaceLeftSlow                = 80,
  kCGSHotKeySpaceRight                   = 81,
  kCGSHotKeySpaceRightSlow               = 82,
  kCGSHotKeySpaceDown                    = 83,
  kCGSHotKeySpaceDownSlow                = 84,
  kCGSHotKeySpaceUp                      = 85,
  kCGSHotKeySpaceUpSlow                  = 86,
  kCGSHotKeyHelp                         = 98
    
} CGSSymbolicHotKey;

typedef struct 
{
  CGSSymbolicHotKey _symbolicKey;
  NSUInteger        _eventFlags;
  NSInteger         _keyCode;
  NSUInteger        _modifierFlags;
  NSInteger         unknown[9];
} CGSHotKeyRepresentation;

typedef NSInteger CGSConnectionID;

extern CGSConnectionID CGSMainConnectionID (void);
extern bool CGSIsSymbolicHotKeyEnabled(CGSSymbolicHotKey hotKey);
extern CGError CGSSetSymbolicHotKey(CGSConnectionID cid, NSUInteger dataCode, CGSSymbolicHotKey hotKey);
extern CGError CGSSetSymbolicHotKeyEnabled(CGSSymbolicHotKey hotKey, bool enabled);
extern CGError CGSGetSymbolicHotKeyValue(CGSSymbolicHotKey hotkey, unsigned short *eventFlags, unsigned short *keyCode, NSUInteger *modifierFlags);
extern CGError CGSSetSymbolicHotKeyValue(CGSSymbolicHotKey hotkey, NSUInteger eventFlags, NSUInteger keyCode, NSUInteger modifierFlags);
extern CGError CGSGetSymbolicHotKeyRepresentation(CGSSymbolicHotKey hotkey, CGSHotKeyRepresentation *representation, NSInteger representationSize);
extern CGError CGSSetSymbolicHotKeyRepresentation(CGSSymbolicHotKey hotkey, CGSHotKeyRepresentation *representation, NSInteger representationSize);

typedef enum
{
  kCGSGlobalHotKeyEnable = 0,
  kCGSGlobalHotKeyDisable,
  kCGSGlobalHotKeyDisableAllButUniversalAccess

} CGSGlobalHotKeyOperatingMode;

extern CGError CGSGetGlobalHotKeyOperatingMode(CGSConnectionID cid, CGSGlobalHotKeyOperatingMode *outMode);
extern CGError CGSSetGlobalHotKeyOperatingMode(CGSConnectionID cid, CGSGlobalHotKeyOperatingMode mode);



extern mach_port_t _CGSDefaultConnection(void);

extern void CGSSetHotKeyWithExclusion(mach_port_t connection, int uid, unsigned short options, unsigned short key, unsigned int modifier_flags, int exclusion);

extern void CGSSetHotKey (mach_port_t connection, int uid, int options, unsigned short key, unsigned int modifier_flags);
extern BOOL CGSGetHotKey (mach_port_t connection, int uid, int *options, unsigned short *key, unsigned int *modifier_flags);
extern void CGSRemoveHotKey(mach_port_t connection, int uid);

extern void CGSSetHotKeyEnabled(mach_port_t connection, int uid, BOOL onOff);
extern BOOL CGSIsHotKeyEnabled (mach_port_t connection, int uid);

} // extern "C"

#endif // CGSHOTKEYS_H

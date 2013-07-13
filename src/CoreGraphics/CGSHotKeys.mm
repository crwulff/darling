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

#include "CGSHotKeys.h"

CGSConnectionID CGSMainConnectionID(void)
{
  // TODO
  return 0;
}

bool CGSIsSymbolicHotKeyEnabled(CGSSymbolicHotKey hotKey)
{
  // TODO
  return false;
}

CGError CGSSetSymbolicHotKey(CGSConnectionID cid, NSUInteger dataCode, CGSSymbolicHotKey hotKey)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSSetSymbolicHotKeyEnabled(CGSSymbolicHotKey hotKey, bool enabled)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSGetSymbolicHotKeyValue(CGSSymbolicHotKey hotkey, unsigned short *eventFlags, unsigned short *keyCode, NSUInteger *modifierFlags)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSSetSymbolicHotKeyValue(CGSSymbolicHotKey hotkey, NSUInteger eventFlags, NSUInteger keyCode, NSUInteger modifierFlags)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSGetSymbolicHotKeyRepresentation(CGSSymbolicHotKey hotkey, CGSHotKeyRepresentation *representation, NSInteger representationSize)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSSetSymbolicHotKeyRepresentation(CGSSymbolicHotKey hotkey, CGSHotKeyRepresentation *representation, NSInteger representationSize)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSGetGlobalHotKeyOperatingMode(CGSConnectionID cid, CGSGlobalHotKeyOperatingMode *outMode)
{
  // TODO
  return kCGErrorNotImplemented;
}

CGError CGSSetGlobalHotKeyOperatingMode(CGSConnectionID cid, CGSGlobalHotKeyOperatingMode mode)
{
  // TODO
  return kCGErrorNotImplemented;
}

mach_port_t _CGSDefaultConnection(void)
{
  // TODO
  return 0;
}

void CGSSetHotKeyWithExclusion(mach_port_t connection, int uid, unsigned short options, unsigned short key, unsigned int modifier_flags, int exclusion)
{
  // TODO
}

void CGSSetHotKey (mach_port_t connection, int uid, int options, unsigned short key, unsigned int modifier_flags)
{
  // TODO
}

BOOL CGSGetHotKey (mach_port_t connection, int uid, int *options, unsigned short *key, unsigned int *modifier_flags)
{
  // TODO
  return false;
}

void CGSRemoveHotKey(mach_port_t connection, int uid)
{
  // TODO
}

void CGSSetHotKeyEnabled(mach_port_t connection, int uid, BOOL onOff)
{
  // TODO
}

BOOL CGSIsHotKeyEnabled (mach_port_t connection, int uid)
{
  // TODO
  return false;
}


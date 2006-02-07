// $Id: KeyboardLights.cpp,v 1.2 2006/02/07 18:38:35 gerrit-albrecht Exp $
//
// Miraledon Class Library
// Copyright (C) 2005, 2006 by Gerrit M. Albrecht
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU Lesser General Public
// License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

/// \file KeyboardLights.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MKeyboardLights class.

#include "StdAfx.h"
#include "KeyboardLights.h"

MKeyboardLights::MKeyboardLights()
{
}

MKeyboardLights::~MKeyboardLights()
{
}

void MKeyboardLights::ToggleKey(unsigned char key)
{
  if (m_os.IsPlatformWindows()) {
    BYTE keyboard_state[256];

    VERIFY(::GetKeyboardState(keyboard_state));
    keyboard_state[key] = keyboard_state[key] ^ 1;
    VERIFY(::SetKeyboardState(keyboard_state));
  }
  else if (m_os.IsPlatformNT()) {
    keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
  }
}

void MKeyboardLights::SetCapsLock(BOOL enable)
{
  if (enable) {
    if (! GetCapsLock())
      ToggleCapsLock();
  }
  else {
    if (GetCapsLock())
      ToggleCapsLock();
  }
}

BOOL MKeyboardLights::GetCapsLock()
{
  return (::GetKeyState(VK_CAPITAL) & 0x0001);
}

void MKeyboardLights::ToggleCapsLock()
{
  ToggleKey(VK_CAPITAL);
}

void MKeyboardLights::SetScrollLock(BOOL enable)
{
  if (enable) {
    if (! GetScrollLock())
      ToggleScrollLock();
  }
  else {
    if (GetScrollLock())
      ToggleScrollLock();
  }
}

BOOL MKeyboardLights::GetScrollLock()
{
  return (::GetKeyState(VK_SCROLL) & 0x0001);
}

void MKeyboardLights::ToggleScrollLock()
{
  ToggleKey(VK_SCROLL);
}

void MKeyboardLights::SetNumLock(BOOL enable)
{
  if (enable) {
    if (! GetNumLock())
      ToggleNumLock();
  }
  else {
    if (GetNumLock())
      ToggleNumLock();
  }
}

BOOL MKeyboardLights::GetNumLock()
{
  return (::GetKeyState(VK_NUMLOCK) & 0x0001);
}

void MKeyboardLights::ToggleNumLock()
{
  ToggleKey(VK_NUMLOCK);
}

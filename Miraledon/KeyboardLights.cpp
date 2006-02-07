// File        : KeyboardLights.cpp
// Project     : Miraledon
// Description : Implementation of the class.

#include "StdAfx.h"
#include "KeyboardLights.h"

CKeyboardLights::CKeyboardLights()
{
}

CKeyboardLights::~CKeyboardLights()
{
}

void CKeyboardLights::ToggleKey(unsigned char key)
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

void CKeyboardLights::SetCapsLock(BOOL enable)
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

BOOL CKeyboardLights::GetCapsLock()
{
  return (::GetKeyState(VK_CAPITAL) & 0x0001);
}

void CKeyboardLights::ToggleCapsLock()
{
  ToggleKey(VK_CAPITAL);
}

void CKeyboardLights::SetScrollLock(BOOL enable)
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

BOOL CKeyboardLights::GetScrollLock()
{
  return (::GetKeyState(VK_SCROLL) & 0x0001);
}

void CKeyboardLights::ToggleScrollLock()
{
  ToggleKey(VK_SCROLL);
}

void CKeyboardLights::SetNumLock(BOOL enable)
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

BOOL CKeyboardLights::GetNumLock()
{
  return (::GetKeyState(VK_NUMLOCK) & 0x0001);
}

void CKeyboardLights::ToggleNumLock()
{
  ToggleKey(VK_NUMLOCK);
}

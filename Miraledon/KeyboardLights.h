// File        : KeyboardLights.h
// Project     : Miraledon
// Description : Declaration of the class.

#pragma once

#include "OperatingSystem.h"

class AFX_EXT_CLASS CKeyboardLights
{
  public:
    CKeyboardLights();
    virtual ~CKeyboardLights();

  public:
    void SetCapsLock(BOOL enable = TRUE);
    BOOL GetCapsLock();
    void ToggleCapsLock();

    void SetScrollLock(BOOL enable = TRUE);
    BOOL GetScrollLock();
    void ToggleScrollLock();

    void SetNumLock(BOOL enable = TRUE);
    BOOL GetNumLock();
    void ToggleNumLock();

  protected:
    void ToggleKey(unsigned char key);

  protected:
    COperatingSystem m_os;
};

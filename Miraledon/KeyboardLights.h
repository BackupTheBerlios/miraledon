// $Id: KeyboardLights.h,v 1.2 2006/02/07 18:38:35 gerrit-albrecht Exp $
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

/// \file KeyboardLights.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MKeyboardLights class.

#pragma once

#include <Miraledon/OperatingSystem.h>

/// \brief Manages the keyboard LEDs.
///
/// This class toggles the LEDs on the keyboard.

class AFX_EXT_CLASS MKeyboardLights
{
  public:
    /// Standard constructor.
    MKeyboardLights();

    /// Destructor.
    virtual ~MKeyboardLights();

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
    MOperatingSystem m_os;
};

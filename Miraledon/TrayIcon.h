// $Id: TrayIcon.h,v 1.2 2006/02/07 15:54:19 gerrit-albrecht Exp $
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

/// \file TrayIcon.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MTrayIcon class.

#pragma once

/// \brief Creates and manages an icon in the tray bar.
///
/// This class manages a single tray bar icon. You have to add an instance
/// to your application to use it.

class MTrayIcon : public CCmdTarget
{
  DECLARE_DYNAMIC(CTrayIcon)

  public:
    MTrayIcon();
    virtual ~MTrayIcon();

    bool AddIcon (unsigned int icon_id, const CString &tip, const CWnd &target);
    bool RemoveIcon ();

  protected:
    NOTIFYICONDATA m_nid;

  protected:
    DECLARE_MESSAGE_MAP()
};

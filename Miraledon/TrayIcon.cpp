// $Id: TrayIcon.cpp,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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

/// \file TrayIcon.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the CTrayIcon class.

#include "StdAfx.h"
#include "TrayIcon.h"

IMPLEMENT_DYNAMIC(CTrayIcon, CCmdTarget)

BEGIN_MESSAGE_MAP(CTrayIcon, CCmdTarget)
END_MESSAGE_MAP()

CTrayIcon::CTrayIcon()
{
  m_nid.cbSize = sizeof(NOTIFYICONDATA);
}

CTrayIcon::~CTrayIcon()
{
}

bool CTrayIcon::AddIcon (unsigned int icon_id, const CString &tip, const CWnd &target)
{
  HINSTANCE inst;
  HANDLE    icon;

  inst = AfxFindResourceHandle(MAKEINTRESOURCE(icon_id), RT_GROUP_ICON);
  icon = LoadImage(inst, MAKEINTRESOURCE(icon_id), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);

  m_nid.hWnd = target;
  m_nid.uID = icon_id;
  m_nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
  //m_nid.uCallbackMessage = WM_TASKBAR; // my user message
  m_nid.hIcon = (HICON)icon;

  if (tip.GetLength() > 0) {
    lstrcpyn(m_nid.szTip, tip, sizeof(m_nid.szTip));
  }
  else {
    m_nid.szTip[0] = '\0';
  }

  Shell_NotifyIcon(NIM_ADD, &m_nid);

  return true;                                             // No errors.
}

bool CTrayIcon::RemoveIcon ()
{
  Shell_NotifyIcon(NIM_DELETE, &m_nid);

  return true;                                             // No errors.
}

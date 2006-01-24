// $Id: OperatingSystem.cpp,v 1.1 2006/01/24 08:39:35 gerrit-albrecht Exp $
//
// Miraledon
// Copyright (C) 2006 by Gerrit M. Albrecht
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA 02110-1301, USA.

#include "StdAfx.h"
#include "OperatingSystem.h"

COperatingSystem::COperatingSystem()
{
  m_is_valid = FALSE;

  m_os_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

  if (GetVersionEx(&m_os_version_info) != 0)
    m_is_valid = TRUE;
}

COperatingSystem::~COperatingSystem()
{
}

BOOL COperatingSystem::IsValid() const
{
  return m_is_valid;
}

BOOL COperatingSystem::IsWindowsNT40() const
{
  if (! m_is_valid)
    return FALSE;

  if (m_os_version_info.dwPlatformId == VER_PLATFORM_WIN32_NT &&
      m_os_version_info.dwMajorVersion == 4)
    return TRUE;

  return FALSE;
}

DWORD COperatingSystem::PlatformID() const
{
  return m_os_version_info.dwPlatformId;
}

DWORD COperatingSystem::MajorVersion() const
{
  return m_os_version_info.dwMajorVersion;
}

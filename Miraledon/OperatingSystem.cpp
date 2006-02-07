// $Id: OperatingSystem.cpp,v 1.3 2006/02/07 20:31:39 gerrit-albrecht Exp $
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

/// \file OperatingSystem.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MOperatingSystem class.

#include "StdAfx.h"
#include "OperatingSystem.h"

MOperatingSystem::MOperatingSystem()
{
  m_is_valid = FALSE;

  m_os_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

  if (GetVersionEx(&m_os_version_info) != 0)
    m_is_valid = TRUE;
}

MOperatingSystem::~MOperatingSystem()
{
}

BOOL MOperatingSystem::IsValid() const
{
  return m_is_valid;
}

BOOL MOperatingSystem::IsWindowsNT40() const
{
  if (! m_is_valid)
    return FALSE;

  if (m_os_version_info.dwPlatformId == VER_PLATFORM_WIN32_NT &&
      m_os_version_info.dwMajorVersion == 4)
    return TRUE;

  return FALSE;
}

DWORD MOperatingSystem::PlatformID() const
{
  return m_os_version_info.dwPlatformId;
}

DWORD MOperatingSystem::MajorVersion() const
{
  return m_os_version_info.dwMajorVersion;
}

BOOL MOperatingSystem::IsPlatformWindows()
{
  if (m_os_version_info.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsPlatformNT()
{
  if (m_os_version_info.dwPlatformId == VER_PLATFORM_WIN32_NT)
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindows3x()
{
  if (m_os_version_info.dwPlatformId == VER_PLATFORM_WIN32s)    // Win3x+Win32s
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindows95()
{
  if (! IsPlatformWindows())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 4) && (m_os_version_info.dwMinorVersion == 0))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindows98()
{
  if (! IsPlatformWindows())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 4) && (m_os_version_info.dwMinorVersion == 10))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsME()
{
  if (! IsPlatformWindows())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 4) && (m_os_version_info.dwMinorVersion == 90))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindows9x()
{
  if (IsWindows98())
    return TRUE;

  if (IsWindows95())
    return TRUE;

  if (IsWindowsME())
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsNT40()
{
  if (! IsPlatformNT())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 4) && (m_os_version_info.dwMinorVersion == 0))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsNT351()
{
  if (! IsPlatformNT())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 3) && (m_os_version_info.dwMinorVersion == 51))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsNT()
{
  if (IsWindowsNT40())
    return TRUE;

  if (IsWindowsNT351())
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindows2000()
{
  if (! IsPlatformNT())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 5) && (m_os_version_info.dwMinorVersion == 0))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsXP()
{
  if (! IsPlatformNT())
    return FALSE;

  if ((m_os_version_info.dwMajorVersion == 5) && (m_os_version_info.dwMinorVersion == 1))
    return TRUE;

  return FALSE;
}

BOOL MOperatingSystem::IsWindowsDotNet()
{
  return IsWindowsXP();
}

CString MOperatingSystem::GetOperatingSystemName()
{
  CString os;

  switch (m_os_version_info.dwPlatformId) {
    case VER_PLATFORM_WIN32s:
      os = _T("Win32s");
      break;

    case VER_PLATFORM_WIN32_WINDOWS:
      os = _T("Windows 9x");

      if ((4 == m_os_version_info.dwMajorVersion) && (0 == m_os_version_info.dwMinorVersion))
        os = _T("Windows 95");

      if ((4 == m_os_version_info.dwMajorVersion) && (10 == m_os_version_info.dwMinorVersion))
        os = _T( "Windows 98" );

      if ((4 == m_os_version_info.dwMajorVersion) && (90 == m_os_version_info.dwMinorVersion))
        os = _T("Windows ME");
      break;

    case VER_PLATFORM_WIN32_NT:
      os = _T("Windows NT");

      if ((3 == m_os_version_info.dwMajorVersion) && (51 == m_os_version_info.dwMinorVersion))
        os = _T("Windows NT 3.51");

      if ((4 == m_os_version_info.dwMajorVersion) && (0 == m_os_version_info.dwMinorVersion))
        os = _T("Windows NT 4.0");

      if ((5 == m_os_version_info.dwMajorVersion) && (0 == m_os_version_info.dwMinorVersion))
        os = _T("Windows 2000");

      if ((5 == m_os_version_info.dwMajorVersion) && (1 == m_os_version_info.dwMinorVersion))
        os = _T("Windows XP");

      break;
	}

  return os;
}

CString MOperatingSystem::GetOperatingSystemVersion()
{
  CString str;

  str.Format(_T("%s (Version %d.%d build %d %s)"),
             GetOperatingSystemName(),
             m_os_version_info.dwMajorVersion,
             m_os_version_info.dwMinorVersion,
             LOWORD(m_os_version_info.dwBuildNumber),   // & 0xffff
             m_os_version_info.szCSDVersion);

  return str;
}

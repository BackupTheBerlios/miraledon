// $Id: ProcessInformation.cpp,v 1.4 2006/02/06 12:39:17 gerrit-albrecht Exp $
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

/// \file ProcessInformation.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the CProcessInformation class.

#include "StdAfx.h"
#include "ProcessInformation.h"
#include "OperatingSystem.h"

// 4101: unreferenced local variable
// 4189: local variable is initialized but not referenced

#pragma warning(disable: 4101 4189)

CProcessInformation::CProcessInformation()
{
}

CProcessInformation::~CProcessInformation()
{
}

// Enumerates processes the Microsoft way:
// http://support.microsoft.com/default.aspx?scid=kb;en-us;Q175030

BOOL CProcessInformation::EnumProcs32(PROCENUMPROC lpProc, LPARAM lParam)
{
  COperatingSystem os;

  HMODULE        lib1 = NULL;
  HMODULE        lib2 = NULL;
  HANDLE         snap = NULL;
  LPDWORD        pids = NULL;
  BOOL           flag;
  HANDLE         proc;
  PROCESSENTRY32 procentry;

  if (os.IsValid() == FALSE)
    return FALSE;

  // ToolHelp Function Pointers.
  HANDLE (WINAPI *lpfCreateToolhelp32Snapshot)(DWORD, DWORD);
  BOOL (WINAPI *lpfProcess32First)(HANDLE, LPPROCESSENTRY32);
  BOOL (WINAPI *lpfProcess32Next)(HANDLE, LPPROCESSENTRY32);

  // PSAPI Function Pointers.
  BOOL (WINAPI *lpfEnumProcesses)(DWORD *, DWORD, DWORD *);
  BOOL (WINAPI *lpfEnumProcessModules)(HANDLE, HMODULE *, DWORD, LPDWORD);
  DWORD (WINAPI *lpfGetModuleBaseName)(HANDLE, HMODULE, LPTSTR, DWORD);

  // VDMDBG Function Pointers.
  INT (WINAPI *lpfVDMEnumTaskWOWEx)(DWORD, TASKENUMPROCEX, LPARAM);

  if ((os.PlatformID() == VER_PLATFORM_WIN32_WINDOWS) ||
      (os.PlatformID() == VER_PLATFORM_WIN32_NT && os.MajorVersion() > 4)) {

    try {
      lib1 = LoadLibraryA("Kernel32.DLL");
      if (lib1 == NULL)
        throw 1;

      // Get procedure addresses. We are linking to these functions explicitly,
      // because a module using this code would fail to load under Windows NT,
      // which does not have the Toolhelp32 functions in KERNEL32.DLL.

      lpfCreateToolhelp32Snapshot = (HANDLE (WINAPI *)(DWORD,DWORD))
        GetProcAddress(lib1, "CreateToolhelp32Snapshot");
#ifdef _UNICODE
      lpfProcess32First = (BOOL (WINAPI *)(HANDLE,LPPROCESSENTRY32W))
        GetProcAddress(lib1, "Process32FirstW");
      lpfProcess32Next = (BOOL (WINAPI *)(HANDLE,LPPROCESSENTRY32W))
        GetProcAddress(lib1, "Process32NextW");
#else
      lpfProcess32First = (BOOL (WINAPI *)(HANDLE,LPPROCESSENTRY32))
        GetProcAddress(lib1, "Process32First");
      lpfProcess32Next = (BOOL (WINAPI *)(HANDLE,LPPROCESSENTRY32))
        GetProcAddress(lib1, "Process32Next");
#endif

      if (lpfProcess32Next == NULL || lpfProcess32First == NULL || lpfCreateToolhelp32Snapshot == NULL)
        throw 2;

      if (os.PlatformID() == VER_PLATFORM_WIN32_NT) {   // If NT-based OS, load VDMDBG.DLL.
        lib2 = LoadLibraryA("VDMDBG.DLL");
        if (lib2 == NULL)
          throw 3;

        lpfVDMEnumTaskWOWEx = (INT (WINAPI *)(DWORD, TASKENUMPROCEX, LPARAM))
          GetProcAddress(lib2, "VDMEnumTaskWOWEx");

        if (lpfVDMEnumTaskWOWEx == NULL)
          throw 4;
      }

      // Get a handle to a Toolhelp snapshot of all processes.

      snap = lpfCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
      if (snap == INVALID_HANDLE_VALUE)
        throw 5;
 
      // Get the information for the first process.

      procentry.dwSize = sizeof(PROCESSENTRY32);
      flag = lpfProcess32First(snap, &procentry);

      while (flag) {                     // While there are processes, keep looping.

        // Call the enum func with the filename and ProcID.

        if (lpProc(procentry.th32ProcessID, 0, procentry.szExeFile, lParam)) {

          // Did we just bump into an NTVDM?

          if (/*stricmp*/_wcsicmp(procentry.szExeFile, _T("NTVDM.EXE")) == 0) {
            typedef struct {
              DWORD          dwPID;
              PROCENUMPROC   lpProc;
              DWORD          lParam;
              BOOL           bEnd;
            } EnumInfoStruct;

            EnumInfoStruct info;
#if 0
            // Fill in some info for the 16-bit enum proc.
            info.dwPID  = procentry.th32ProcessID;
            info.lpProc = lpProc;
            info.lParam = (DWORD) lParam;
            info.bEnd   = FALSE;

            // Enum the 16-bit stuff.
            lpfVDMEnumTaskWOWEx(procentry.th32ProcessID, (TASKENUMPROCEX) Enum16, (LPARAM) &info);

            // Did our main enum func say quit?
            if (info.bEnd)
              break;
#endif
          }

          procentry.dwSize = sizeof(PROCESSENTRY32W);
          flag = lpfProcess32Next(snap, &procentry);
        } else {
          flag = FALSE;
        }
      }

      throw 0;  // Clean up everything.
    }

    catch (int ex) {
      TRACE("GOT EXCEPTION: %d\n", ex);

      if (lib1)
        FreeLibrary(lib1);

      if (lib2)
        FreeLibrary(lib2);

      if (ex > 0)
        return FALSE;
    }
  }

  return TRUE;
}

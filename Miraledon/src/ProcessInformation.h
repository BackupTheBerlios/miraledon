// $Id: ProcessInformation.h,v 1.6 2006/01/24 10:48:48 gerrit-albrecht Exp $
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

/// \file ProcessInformation.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CProcessInformation class.

#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <vdmdbg.h>

typedef BOOL (CALLBACK *PROCENUMPROC)(DWORD, WORD, LPTSTR, LPARAM);

BOOL CALLBACK MyProcessEnumerator(DWORD dwPID, WORD wTask, LPCTSTR szProcess, LPARAM lParam);

/// \brief Gets information about running processes.
///
/// This class retrieves information about running processes from the operating system. It's able to
/// enumerate the processes calling a callback function once for each process. The callback function
/// has to be defined by the user.

class CProcessInformation : public CObject
{
  public:
    /// Standard constructor.
    CProcessInformation();

    /// Destructor.
    virtual ~CProcessInformation();

    /// Enumerates all processes and calls a callback function for each process.
    ///
    /// \param lpProc is a pointer to the callback function.
    /// \param lParam is an arbitrary value which is passed to the callback function as a parameter.
    ///        Here you may give a pointer to an object which you may reference from that function.
    /// \return Returns TRUE on success and FALSE on error.
    BOOL EnumProcs32(PROCENUMPROC lpProc, LPARAM lParam);
};


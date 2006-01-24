// $Id: OperatingSystem.h,v 1.2 2006/01/24 10:48:48 gerrit-albrecht Exp $
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

/// \file OperatingSystem.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the COperatingSystem class.

#pragma once

/// \brief Retrieves the operating system version and allows comparisations
/// against it.
///
/// Upon construction, this class asks the operating system to give
/// us some information about itself. These values are stored and
/// other methods allow comparisations to check if it is a certain
/// well known operating system or platform or not.

class COperatingSystem : public CObject
{
  public:
    /// Standard constructor.
    COperatingSystem();

    /// Destructor.
    virtual ~COperatingSystem();

    /// Determines if the returned values of the methods are correct.
    ///
    /// \return Returns TRUE if the data contained in the object is valid,
    ///         returns FALSE if there was an error while retrieving the data.
    BOOL IsValid() const;

    /// Compares to operating system to Windows NT 4.0.
    ///
    /// \return Returns TRUE if it is a Windows NT 4.0 system, else FALSE.
    BOOL IsWindowsNT40() const;

    DWORD PlatformID() const;
    DWORD MajorVersion() const;

  protected:
    OSVERSIONINFO m_os_version_info;             ///< Internal data retrieved from Windows.
    BOOL          m_is_valid;                    ///< Success state of the data retrieval.
};


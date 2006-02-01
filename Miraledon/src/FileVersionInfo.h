// $Id: FileVersionInfo.h,v 1.5 2006/02/01 15:09:18 gerrit-albrecht Exp $
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

/// \file FileVersionInfo.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CFileVersionInfo class.

#pragma once

#include <windows.h>

/// Gets information about the current application.
///
/// This class retrieves information about the running application from the operating system.
/// It's able to return version number, manufacturer, copyright holder and much more
/// information. Upon construction, this class retrieves it's data using windows API calls
/// and stores everything for later retrieval.

class CFileVersionInfo
{
  public:
    /// Standard constructor.
    CFileVersionInfo();

    /// Destructor.
    virtual ~CFileVersionInfo();

  public:
    /// Grabs the version information from the given file and holds its data using
    /// separate class members.
    ///
    /// \param filename is the name of the file or module (dll) from which the
    ///        version information should be retrieved.
    /// \return Returns TRUE on success and FALSE on error.
    BOOL Get(const CString &filename);

    /// Frees all used buffers.
    void Free();

    /// Retrieves a the value of a field from the version info data member.
    ///
    /// \param fieldname is the name of the field whose information should
    ///        be extracted and returned.
    /// \return Returns the string value of the named field.
    CString QueryValue(const CString &fieldname, DWORD langcharset = 0);

    CString GetFileDescription()  { return QueryValue(_T("FileDescription"));  }
    CString GetFileVersion()      { return QueryValue(_T("FileVersion"));      }
    CString GetInternalName()     { return QueryValue(_T("InternalName"));     }
    CString GetCompanyName()      { return QueryValue(_T("CompanyName"));      }
    CString GetLegalCopyright()   { return QueryValue(_T("LegalCopyright"));   }
    CString GetOriginalFilename() { return QueryValue(_T("OriginalFilename")); }
    CString GetProductName()      { return QueryValue(_T("ProductName"));      }
    CString GetProductVersion()   { return QueryValue(_T("ProductVersion"));   }

  protected:
    LPBYTE m_version_info_data;              ///< Holds the retrieved version information block.
    DWORD  m_lang_charset;
};

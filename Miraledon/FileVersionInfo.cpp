// $Id: FileVersionInfo.cpp,v 1.3 2006/02/22 11:19:15 gerrit-albrecht Exp $
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

/// \file FileVersionInfo.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MFileVersionInfo class.

#include "StdAfx.h"
#include "FileVersionInfo.h"

// 4101: unreferenced local variable
// 4189: local variable is initialized but not referenced

#pragma warning(disable: 4101 4189)

#pragma comment(lib, "version")

MFileVersionInfo::MFileVersionInfo()
{
  m_version_info_data = 0;
  m_lang_charset      = 0;
}

MFileVersionInfo::~MFileVersionInfo()
{
  Free();
}

BOOL MFileVersionInfo::Get(const CString &filename)
{
  DWORD handle;
  DWORD length;

  ASSERT(filename.GetLength() > 0);
  ASSERT(m_version_info_data == 0);

  length = GetFileVersionInfoSize(filename, &handle);
  if (length == 0)
    return FALSE;

  m_version_info_data = new BYTE[length];
  if (! GetFileVersionInfo(filename, handle, length, m_version_info_data)) {
    Free();
    return FALSE;
  }

  UINT   query_size;
  DWORD *trans_table;

  // Retrieve the first language and character-set identifier.

  if (! ::VerQueryValue(m_version_info_data, _T("\\VarFileInfo\\Translation"),
                        (void **)&trans_table, &query_size)) {
    Free();
    return FALSE;
  }

  // Swap the words to have lang-charset in the correct format.
  m_lang_charset = MAKELONG(HIWORD(trans_table[0]), LOWORD(trans_table[0]));

  return TRUE;
}

void MFileVersionInfo::Free()
{
  if (m_version_info_data) {
    delete [] m_version_info_data;
    m_version_info_data = 0;
  }
}

CString MFileVersionInfo::QueryValue(const CString &fieldname, DWORD langcharset)
{
  CString result = _T("");

  ASSERT(m_version_info_data);

  if (m_version_info_data == 0)
    return result;

  if (langcharset == 0)                                    // No lang-charset specified, use default.
    langcharset = m_lang_charset;

  UINT nQuerySize;
  LPVOID lpData;
  CString strBlockName;

  strBlockName.Format(_T("\\StringFileInfo\\%08lx\\%s"), langcharset, fieldname);
  if (VerQueryValue((void **)m_version_info_data, strBlockName.GetBuffer(0), &lpData, &nQuerySize))
    result = (LPCTSTR)lpData;

  strBlockName.ReleaseBuffer();

  return result;
}

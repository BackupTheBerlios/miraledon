// $Id: FileDialog.h,v 1.1 2006/02/22 15:24:39 gerrit-albrecht Exp $
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

/// \file FileDialog.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MFileDialog class.

#pragma once

/// \brief An enhanced CFileDialog.
///
/// Removes a bug, where a limited buffer size cutted the selected file
/// path data if to many files where selected at once.

class AFX_EXT_CLASS MFileDialog : public CFileDialog
{
  DECLARE_DYNAMIC(MFileDialog)

  public:
    MFileDialog(BOOL bOpenFileDialog,       // TRUE for FileOpen, FALSE for FileSaveAs
                LPCTSTR lpszDefExt = NULL,
                LPCTSTR lpszFileName = NULL,
                DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                LPCTSTR lpszFilter = NULL,
                CWnd* pParentWnd = NULL);
    virtual ~MFileDialog();

  protected:
    DECLARE_MESSAGE_MAP()
};

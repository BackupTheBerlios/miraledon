// $Id: FileDialog.cpp,v 1.1 2006/02/22 15:24:39 gerrit-albrecht Exp $
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
/// \brief Contains the definition of the MFileDialog class.

#include "StdAfx.h"
#include "FileDialog.h"

IMPLEMENT_DYNAMIC(MFileDialog, CFileDialog)

BEGIN_MESSAGE_MAP(MFileDialog, CFileDialog)
END_MESSAGE_MAP()

MFileDialog::MFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
                         DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd)
 : CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MFileDialog::~MFileDialog()
{
}

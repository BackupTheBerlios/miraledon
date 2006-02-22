// $Id: ColorButtonDialog.cpp,v 1.1 2006/02/22 15:24:39 gerrit-albrecht Exp $
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

/// \file ColorButtonDialog.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MColorButtonDialog class.

#include "StdAfx.h"
#include "ColorButtonDialog.h"

#include <Resource.h>

IMPLEMENT_DYNAMIC(MColorButtonDialog, CDialog)

BEGIN_MESSAGE_MAP(MColorButtonDialog, CDialog)
END_MESSAGE_MAP()

MColorButtonDialog::MColorButtonDialog(CWnd* pParent /* = NULL */)
 : CDialog(IDD_MIRA_COLOR_BUTTON, pParent)
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MColorButtonDialog::~MColorButtonDialog()
{
}

void MColorButtonDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
}

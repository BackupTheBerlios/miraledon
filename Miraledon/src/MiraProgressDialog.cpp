// $Id: MiraProgressDialog.cpp,v 1.1 2006/02/06 15:22:28 gerrit-albrecht Exp $
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

/// \file MiraProgressDialog.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the CMiraProgressDialog class.

#include "StdAfx.h"
#include "MiraProgressDialog.h"

IMPLEMENT_DYNAMIC(CMiraProgressDialog, CMiraDialog)

BEGIN_MESSAGE_MAP(CMiraProgressDialog, CMiraDialog)
END_MESSAGE_MAP()

CMiraProgressDialog::CMiraProgressDialog(UINT idd, CWnd *parent /* = NULL */)
 : CMiraDialog(idd, parent)
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

CMiraProgressDialog::~CMiraProgressDialog()
{
}

void CMiraProgressDialog::DoDataExchange(CDataExchange* pDX)
{
  CMiraDialog::DoDataExchange(pDX);
}

// $Id: AboutDialog.cpp,v 1.4 2006/02/23 12:37:59 gerrit-albrecht Exp $
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

/// \file AboutDialog.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MAboutDialog class.

#include "StdAfx.h"
#include "AboutDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(MAboutDialog, CDialog)
END_MESSAGE_MAP()

MAboutDialog::MAboutDialog(unsigned int id /* = 0 */)
{
  if (id == 0) {                                           // Use the built in dialog resource.
    TRACE("MAboutDialog::MAboutDialog: Error: TODO\n");

  }

  CDialog::CDialog(id);

  EnableActiveAccessibility();
}

MAboutDialog::~MAboutDialog()
{
}

void MAboutDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
}

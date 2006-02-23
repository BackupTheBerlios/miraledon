// $Id: AboutDialog.h,v 1.5 2006/02/23 12:38:00 gerrit-albrecht Exp $
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
/// \brief Contains the declaration of the MAboutDialog class.

#pragma once

/// \brief This is a better CAboutDialog.
///
/// This is the standard implementation with some prepositioned controls.
/// This allows you to add a simple about dialog to your programs without
/// inserting an extra class. Even the dialog resource is optional. This
/// dialog is able to retrieve most of its information from the version
/// info block of the executable.

class AFX_EXT_CLASS MAboutDialog : public CDialog
{
  public:
    /// Standard constructor.
    MAboutDialog(unsigned int id = 0);

    /// Destructor.
    virtual ~MAboutDialog();

  protected:
    virtual void DoDataExchange(CDataExchange* pDX);

  protected:
    DECLARE_MESSAGE_MAP()
};

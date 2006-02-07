// $Id: ProgressDialog.h,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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
/// \brief Contains the declaration of the CMiraProgressDialog class.

#pragma once

#include "MiraDialog.h"

/// \brief This class implements a progress dialog.
///
/// CMiraProgressDialog is an extension for the CMiraDialog class.
/// It dispalys a progress bar, an animation, a current action text
/// and an percent value for the progress. This dialog contains only
/// a cancel button.

class CMiraProgressDialog : public CMiraDialog
{
  DECLARE_DYNAMIC(CMiraProgressDialog)

  public:
    /// Standard constructor.
    CMiraProgressDialog(UINT idd, CWnd *parent = NULL);

    /// Destructor.
    virtual ~CMiraProgressDialog();

  protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    DECLARE_MESSAGE_MAP()
};

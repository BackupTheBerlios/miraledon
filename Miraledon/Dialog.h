// $Id: Dialog.h,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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

/// \file MiraDialog.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CMiraDialog class.

#pragma once

#include "SizeGrip.h"

/// \brief This is an enhanced CDialog.
///
/// This class is able to show a size grip an it's corner.
/// More features will follow.

class CMiraDialog : public CDialog
{
  DECLARE_DYNAMIC(CMiraDialog)

  public:
    /// Standard constructor.
    CMiraDialog(UINT idd, CWnd *parent = 0);

    /// Destructor.
    virtual ~CMiraDialog();

  protected:
    /// Enables the size grip for this dialog.
    void EnableSizeGrip(bool enable = true);

    /// Creates a size grip for this dialog.
    ///
    /// Call this member from OnInitDialog
    void CreateSizeGrip(bool visible = true);

    /// Creates the tooltip control which shows hints to the dialog items.
    void CreateToolTip();

    /// Adds a reference from the dialog items to a ressource string
    /// using the items's own ID as string ID.
    ///
    /// First call CreateToolTip, e.g.
    /// from OnInitDialog(). Then add all widgets and other elements and
    /// after this step you can call AddToolTips(). To add a tooltip to a
    /// control, just add a string resource using the same ID as the control
    /// to get the tip.
    void AddToolTips();

    virtual void DoDataExchange(CDataExchange *pDX);

    DECLARE_MESSAGE_MAP()

  protected:
    bool          m_size_grip_created;
    CSizeGrip     m_size_grip;
    bool          m_tooltip_created;
    CToolTipCtrl  m_tooltip;
    UINT          m_min_size_x;
    UINT          m_min_size_y;

  public:
    afx_msg void OnPaint();
    afx_msg LRESULT OnNcHitTest(CPoint point);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};

// $Id: TabCtrl.h,v 1.3 2006/02/22 14:16:22 gerrit-albrecht Exp $
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

/// \file TabCtrl.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MTabCtrl class.

#pragma once

/// \brief Creates and manages a tab control.
///
/// This class manages an extended tab control. There are some more methods to work
/// with the tab control. Future extensions should provide a close button and/or
/// a close context menu item for dynamically created tabs.

class AFX_EXT_CLASS MTabCtrl : public CTabCtrl
{
  DECLARE_DYNAMIC(MTabCtrl)

  public:
    /// Standard constructor.
    MTabCtrl();

    /// Destructor.
    virtual ~MTabCtrl();

    void AddTab(const CString &name);

    void DeleteTab(const unsigned int pos = 0);

    /// Use this method to show the needed and hide all unneeded controls.
    virtual void TabActivated(unsigned int tab);
	
    /// Display and manage a close button.
    void DisplayCloseButton(bool show = true);

  protected:
    bool    m_use_close_button;                            ///< Manage a close button.
	CButton m_close_button;                                ///< Button to close the current tab.

  public:
    afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);

  protected:
    DECLARE_MESSAGE_MAP()
};

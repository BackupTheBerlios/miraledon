// $Id: ListCtrl.h,v 1.4 2006/02/08 12:53:45 gerrit-albrecht Exp $
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

/// \file ListCtrl.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MListCtrl class.

#pragma once

/// \brief This is an enhanced CListCtrl.
///
/// This class is able to autosize it's columns.
/// More features will follow.

class AFX_EXT_CLASS MListCtrl : public CListCtrl
{
  DECLARE_DYNAMIC(MListCtrl)

  public:
    MListCtrl();
    virtual ~MListCtrl();

    void AutoSizeColumn(int col);
    void AutoSizeColumns();
    int GetColumnCount() const;

	BOOL AddColumn(LPCTSTR strItem,int nItem,int nSubItem = -1,
                   int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM,
                   int nFmt = LVCFMT_LEFT);
	BOOL AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex = -1);
	BOOL ReplaceItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex = -1);

  protected:
    DECLARE_MESSAGE_MAP()
};

// $Id: ListCtrl.cpp,v 1.2 2006/02/07 15:37:02 gerrit-albrecht Exp $
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

#include "StdAfx.h"
#include "ListCtrl.h"

IMPLEMENT_DYNAMIC(MListCtrl, CListCtrl)

BEGIN_MESSAGE_MAP(MListCtrl, CListCtrl)
END_MESSAGE_MAP()

MListCtrl::MListCtrl()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MListCtrl::~MListCtrl()
{
}

int MListCtrl::GetColumnCount() const
{
  CHeaderCtrl *hdr = (CHeaderCtrl *) GetDlgItem(0);        // Get the header control.

  return hdr->GetItemCount();
}

// Author: Roger Onslow
//
// Call this after your list control is filled.
//
// If you don't supply a column number, it will resize all columns.
// If you do supply a column numner, it will resize that column only.
// For example, you may only want to resize the first column when you
// do label editing (or another column if you use inplace cell editing
// or combos). But you might want to resize all columns after loading
// the list control with data.
//
// Notice the use of SetRedraw to stop flickering. You should use
// my custom version of this to avoid problems with nested calls to
// SetRedraw (and to remove the need for a final call to Invalidate()).

void MListCtrl::AutoSizeColumn(int col)
{
  const int MINCOLWIDTH = 10;

  SetRedraw(FALSE);

  SetColumnWidth(col, LVSCW_AUTOSIZE);
  int wc1 = GetColumnWidth(col);

  SetColumnWidth(col, LVSCW_AUTOSIZE_USEHEADER);
  int wc2 = GetColumnWidth(col);

  SetColumnWidth(col, max(MINCOLWIDTH, max(wc1, wc2)));

  SetRedraw(TRUE);
  Invalidate();
}

void MListCtrl::AutoSizeColumns()
{
  SetRedraw(FALSE);

  int maxcol = GetColumnCount() - 1;

  for (int col = 0; col <= maxcol; col++) {
    AutoSizeColumn(col);
  }

  // RecalcHeaderTips(); *** uncomment this if you use my header tips method

  SetRedraw(TRUE);
  Invalidate();
}

BOOL MListCtrl::AddColumn(LPCTSTR strItem,int nItem,int nSubItem,int nMask,int nFmt)
{
	LV_COLUMN lvc;
	lvc.mask = nMask;
	lvc.fmt = nFmt;
	lvc.pszText = (LPTSTR) strItem;
	lvc.cx = GetStringWidth(lvc.pszText) + 15;

  if (nMask & LVCF_SUBITEM) {
		if(nSubItem != -1)
			lvc.iSubItem = nSubItem;
		else
			lvc.iSubItem = nItem;
  }

  return InsertColumn(nItem,&lvc);
}

BOOL MListCtrl::AddItem(int nItem, int nSubItem, LPCTSTR strItem, int nImageIndex)
{
  LV_ITEM item;

  item.mask     = LVIF_TEXT;
  item.iItem    = nItem;
  item.iSubItem = nSubItem;
  item.pszText  = (LPTSTR) strItem;

  if (nImageIndex != -1) {
    item.mask |= LVIF_IMAGE;
    item.iImage |= LVIF_IMAGE;
  }

  if (nSubItem == 0)
    return InsertItem(&item);

  return SetItem(&item);
}

BOOL MListCtrl::ReplaceItem(int nItem, int nSubItem, LPCTSTR strItem, int nImageIndex)
{
  LV_ITEM item;

  item.mask     = LVIF_TEXT;
  item.iItem    = nItem;
  item.iSubItem = nSubItem;
  item.pszText  = (LPTSTR) strItem;

  if (nImageIndex != -1) {
    item.mask |= LVIF_IMAGE;
    item.iImage |= LVIF_IMAGE;
  }

  return SetItem(&item);
}

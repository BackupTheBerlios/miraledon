// $Id: MiraListCtrl.cpp,v 1.1 2006/01/24 16:41:25 gerrit-albrecht Exp $
//
// Miraledon
// Copyright (C) 2006 by Gerrit M. Albrecht
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA 02110-1301, USA.

#include "StdAfx.h"
#include "MiraListCtrl.h"

IMPLEMENT_DYNAMIC(CMiraListCtrl, CListCtrl)

BEGIN_MESSAGE_MAP(CMiraListCtrl, CListCtrl)
END_MESSAGE_MAP()

CMiraListCtrl::CMiraListCtrl()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

CMiraListCtrl::~CMiraListCtrl()
{
}

int CMiraListCtrl::GetColumnCount() const
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

void CMiraListCtrl::AutoSizeColumn(int col)
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

void CMiraListCtrl::AutoSizeColumns()
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

BOOL CMiraListCtrl::AddColumn(LPCTSTR strItem,int nItem,int nSubItem,int nMask,int nFmt)
{
	LV_COLUMN lvc;
	lvc.mask = nMask;
	lvc.fmt = nFmt;
	lvc.pszText = (LPTSTR) strItem;
	lvc.cx = GetStringWidth(lvc.pszText) + 15;
	if(nMask & LVCF_SUBITEM){
		if(nSubItem != -1)
			lvc.iSubItem = nSubItem;
		else
			lvc.iSubItem = nItem;
	}
	return InsertColumn(nItem,&lvc);
}

BOOL CMiraListCtrl::AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex)
{
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nItem;
	lvItem.iSubItem = nSubItem;
	lvItem.pszText = (LPTSTR) strItem;
	if(nImageIndex != -1){
		lvItem.mask |= LVIF_IMAGE;
		lvItem.iImage |= LVIF_IMAGE;
	}
	if(nSubItem == 0)
		return InsertItem(&lvItem);

  return SetItem(&lvItem);
}

BOOL CMiraListCtrl::ReplaceItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex)
{
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nItem;
	lvItem.iSubItem = nSubItem;
	lvItem.pszText = (LPTSTR) strItem;
	if(nImageIndex != -1){
		lvItem.mask |= LVIF_IMAGE;
		lvItem.iImage |= LVIF_IMAGE;
	}

  return SetItem(&lvItem);
}

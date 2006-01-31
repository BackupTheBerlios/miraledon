// $Id: TreeListView.h,v 1.2 2006/01/31 10:46:57 gerrit-albrecht Exp $
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

#pragma once

class CTreeListView : public CCtrlView
{
    DECLARE_DYNCREATE(CTreeListView)

  protected:
    CTreeListView();           // protected constructor used by dynamic creation
    virtual ~CTreeListView();

/*
// NOTE: The cast in GetListCtrl is ugly, but must be preserved for compatibility.
// CListCtrl is not related to CListView by inheritance so we must be careful to ensure 
// that CListCtrl remains a binary compatible subset of CListView.
_AFXCVIEW_INLINE CListCtrl& CListView::GetListCtrl() const
	{ return *(CListCtrl*)this; }

// NOTE: The cast in GetTreeCtrl is ugly, but must be preserved for compatibility.
// CTreeCtrl is not related to CTreeView by inheritance so we must be careful to ensure 
// that CTreeCtrl remains a binary compatible subset of CTreeView.
_AFXCVIEW_INLINE CTreeCtrl& CTreeView::GetTreeCtrl() const
	{ return *(CTreeCtrl*)this; }
*/

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

  protected:
    DECLARE_MESSAGE_MAP()
};

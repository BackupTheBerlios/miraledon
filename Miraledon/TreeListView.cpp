// $Id: TreeListView.cpp,v 1.2 2006/02/07 15:54:19 gerrit-albrecht Exp $
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
#include "TreeListView.h"

IMPLEMENT_DYNCREATE(MTreeListView, CCtrlView)

BEGIN_MESSAGE_MAP(MTreeListView, CCtrlView)
END_MESSAGE_MAP()

MTreeListView::MTreeListView()
 : CCtrlView(WC_TREEVIEW, AFX_WS_DEFAULT_VIEW)   // We have more common with a tree than with a list view.
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MTreeListView::~MTreeListView()
{
}

#ifdef _DEBUG
void MTreeListView::AssertValid() const
{
  CCtrlView::AssertValid();
}

#ifndef _WIN32_WCE
void MTreeListView::Dump(CDumpContext& dc) const
{
  CCtrlView::Dump(dc);
}
#endif
#endif

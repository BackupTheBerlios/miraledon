// $Id: TabCtrl.cpp,v 1.2 2006/02/15 12:56:59 gerrit-albrecht Exp $
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

/// \file TabCtrl.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MTabCtrl class.

#include "StdAfx.h"
#include "TabCtrl.h"

IMPLEMENT_DYNAMIC(MTabCtrl, CTabCtrl)

BEGIN_MESSAGE_MAP(MTabCtrl, CTabCtrl)
    ON_NOTIFY_REFLECT(TCN_SELCHANGE, &MTabCtrl::OnTcnSelchange)
END_MESSAGE_MAP()

MTabCtrl::MTabCtrl()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MTabCtrl::~MTabCtrl()
{
}

void MTabCtrl::AddTab (const CString &name)
{
  TCITEM tci;
  CRect size;

  tci.mask = TCIF_TEXT;
  tci.pszText = T2W((LPTSTR)(LPCTSTR) name);

  InsertItem(GetItemCount(), &tci);

  GetClientRect(&size);
  AdjustRect(FALSE, &size);
}

void MTabCtrl::DeleteTab (const unsigned int pos /* = 0 */)
{
  DeleteItem(pos);
}

void MTabCtrl::TabActivated (unsigned int tab)
{
}

void MTabCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
  int sel = GetCurSel();

  UNUSED_ALWAYS(pNMHDR);

  TRACE("MTabCtrl::OnTcnSelchange: sel=%d\n", sel);

  TabActivated(sel);

  *pResult = 0;
}

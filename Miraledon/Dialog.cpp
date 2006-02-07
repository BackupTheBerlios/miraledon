// $Id: Dialog.cpp,v 1.2 2006/02/07 15:37:02 gerrit-albrecht Exp $
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

/// \file Dialog.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MDialog class.

#include "StdAfx.h"
#include "Dialog.h"

IMPLEMENT_DYNAMIC(MDialog, CDialog)

BEGIN_MESSAGE_MAP(MDialog, CDialog)
    ON_WM_PAINT()
    ON_WM_NCHITTEST()
    ON_WM_SIZE()
END_MESSAGE_MAP()

MDialog::MDialog(UINT idd, CWnd *parent /* = 0 */)
 : CDialog(idd, parent)
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif

  m_size_grip_created = false;
  m_tooltip_created   = false;
}

MDialog::~MDialog()
{
}

void MDialog::EnableSizeGrip(bool enable /* = true */)
{
  if (! m_size_grip_created) {
    TRACE("MDialog::EnableSizeGrip: No size grip.\n");
    return;
  }

  m_size_grip.ShowWindow((enable) ? SW_SHOW : SW_HIDE);
}

void MDialog::CreateSizeGrip(bool visible /* = true */)
{
  CRect r;
  DWORD style = 0;

  GetClientRect(r);

  r.left = r.right  - GetSystemMetrics(SM_CXHSCROLL);
  r.top  = r.bottom - GetSystemMetrics(SM_CYVSCROLL);

  style = WS_CHILD | SBS_SIZEBOX | SBS_SIZEBOXBOTTOMRIGHTALIGN | SBS_SIZEGRIP;
  if (visible)
    style |= WS_VISIBLE;

  m_size_grip.Create(style, r, this, AFX_IDW_SIZE_BOX);

  // Put it at the correct spot in the z-order, make sure other controls don't obscure it.
  m_size_grip.SetWindowPos(NULL, r.left, r.top, r.Width(), r.Height(), 0);

  // Check if the dialog has a resizable border.
  // If it is missing, we don't need a size grip.

  if ((GetStyle() & WS_THICKFRAME) != WS_THICKFRAME) {
    EnableSizeGrip(false);
    TRACE("MDialog::CreateSizeGrip: No resizable dialog border.\n");
  }

  m_size_grip_created = true;
}

void MDialog::CreateToolTip()
{
  if (! m_tooltip.Create(this)) {
  }

  m_tooltip.Activate(TRUE);

  EnableToolTips(TRUE);

  m_tooltip_created = true;
}

void MDialog::AddToolTips()
{
  int   id;
  CWnd *win;

  if (! m_tooltip_created) {
    TRACE("MDialog::AddToolTips: No tooltip control.\n");
    return;
  }

  win = GetWindow(GW_CHILD);
  while (win) {
    id = win->GetDlgCtrlID();

    if (id != -1)
      m_tooltip.AddTool(win, win->GetDlgCtrlID());

    win = win->GetWindow(GW_HWNDNEXT);
  }
}

// get the dialog size

//GetWindowRect(m_rcDialog);
//m_MinSize.x=m_rcDialog.Width();
//m_MinSize.y=m_rcDialog.Height();

void MDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
}

// Do not call CDialog::OnPaint() for painting messages.

void MDialog::OnPaint()
{
  //CPaintDC dc(this);                             // Device context for painting.

  CDialog::OnPaint();
}

LRESULT MDialog::OnNcHitTest(CPoint point)
{
  LRESULT ht = CDialog::OnNcHitTest(point);

  if (ht == HTCLIENT && m_size_grip_created) {
    if (m_size_grip.IsWindowVisible()) {
      CRect rc;

      GetWindowRect(rc);

      rc.left = rc.right  - GetSystemMetrics(SM_CXHSCROLL);
      rc.top  = rc.bottom - GetSystemMetrics(SM_CYVSCROLL);

      if (rc.PtInRect(point)) {
        ht = HTBOTTOMRIGHT;
      }
    }
  }

  return ht;
}

void MDialog::OnSize(UINT nType, int cx, int cy)
{
  TRACE("MDialog::OnSize\n");

  CDialog::OnSize(nType, cx, cy);

  if (m_size_grip_created) {
    CRect r;

    GetClientRect(r);

    r.left = r.right  - GetSystemMetrics(SM_CXHSCROLL);
    r.top  = r.bottom - GetSystemMetrics(SM_CYVSCROLL);

    // Put it at the correct spot in the z-order, make sure other controls don't obscure it.
    if (m_size_grip.IsWindowVisible())
      m_size_grip.SetWindowPos(&CWnd::wndBottom, r.left, r.top, r.Width(), r.Height(), SWP_SHOWWINDOW);
    else
      m_size_grip.SetWindowPos(&CWnd::wndBottom, r.left, r.top, r.Width(), r.Height(), SWP_HIDEWINDOW);
    //m_size_grip.SetWindowPos(NULL, r.left, r.top, r.Width(), r.Height(), 0);
    //m_size_grip.MoveWindow(r.left, r.top, r.Width(), r.Height());
  }
}

BOOL MDialog::PreTranslateMessage(MSG* pMsg)
{
  if (m_tooltip_created) {
    m_tooltip.RelayEvent(pMsg);
  }

  return CDialog::PreTranslateMessage(pMsg);
}

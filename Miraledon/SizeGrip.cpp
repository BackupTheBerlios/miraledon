// $Id: SizeGrip.cpp,v 1.2 2006/02/07 15:37:02 gerrit-albrecht Exp $
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

/// \file SizeGrip.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MSizeGrip class.

#include "StdAfx.h"
#include "SizeGrip.h"

IMPLEMENT_DYNAMIC(MSizeGrip, CScrollBar)

BEGIN_MESSAGE_MAP(MSizeGrip, CScrollBar)
    ON_WM_NCHITTEST()
END_MESSAGE_MAP()

MSizeGrip::MSizeGrip()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif

}

MSizeGrip::~MSizeGrip()
{
}

BOOL MSizeGrip::IsRTL() const
{
  return GetExStyle() & WS_EX_LAYOUTRTL;
}

LRESULT MSizeGrip::OnNcHitTest(CPoint point)
{
  LRESULT ht = CScrollBar::OnNcHitTest(point);

  if (ht == HTCLIENT) {
    if (IsRTL())
      return HTBOTTOMLEFT;
    else
       return HTBOTTOMRIGHT;
  }

  return ht;
}

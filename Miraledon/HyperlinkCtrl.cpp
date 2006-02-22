// $Id: HyperlinkCtrl.cpp,v 1.3 2006/02/22 14:04:34 gerrit-albrecht Exp $
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

/// \file HyperlinkCtrl.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MHyperlinkCtrl class.

#include "StdAfx.h"
#include "HyperlinkCtrl.h"

IMPLEMENT_DYNAMIC(MHyperlinkCtrl, CStatic)

BEGIN_MESSAGE_MAP(MHyperlinkCtrl, CStatic)
END_MESSAGE_MAP()

MHyperlinkCtrl::MHyperlinkCtrl()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MHyperlinkCtrl::~MHyperlinkCtrl()
{
}

void MHyperlinkCtrl::SetURL(CString url)
{
  m_url = url;
}

CString MHyperlinkCtrl::GetURL() const
{
  return m_url;
}

DWORD MHyperlinkCtrl::GetStyle() const
{
  return m_style;
}

void MHyperlinkCtrl::SetStyle()
{
}

BOOL MHyperlinkCtrl::ModifyStyle(DWORD remove, DWORD add, BOOL apply = TRUE)
{
  return FALSE;
}

BOOL MHyperlinkCtrl::IsVisited() const
{
  return FALSE;
}

void MHyperlinkCtrl::SetVisited(BOOL visited = TRUE)
{
}

void MHyperlinkCtrl::GotoURL(const CString url /* = _T("") */) const
{
}

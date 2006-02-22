// $Id: ColorButton.cpp,v 1.1 2006/02/22 15:24:39 gerrit-albrecht Exp $
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

/// \file ColorButton.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MColorButton class.

#include "StdAfx.h"
#include "ColorButton.h"

IMPLEMENT_DYNAMIC(MColorButton, CButton)

BEGIN_MESSAGE_MAP(MColorButton, CButton)
    ON_WM_DRAWITEM()
    ON_CONTROL_REFLECT(BN_CLICKED, &MColorButton::OnBnClicked)
END_MESSAGE_MAP()

MColorButton::MColorButton()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif
}

MColorButton::~MColorButton()
{
}

COLORREF MColorButton::GetColor() const
{
  return m_color;
}

void MColorButton::SetColor(COLORREF color)
{
  m_color = color;
}

void MColorButton::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{

  CButton::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void MColorButton::OnBnClicked()
{
}

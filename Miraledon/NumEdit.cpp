// $Id: NumEdit.cpp,v 1.2 2006/02/23 12:38:00 gerrit-albrecht Exp $
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

/// \file NumEdit.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MNumEdit class.

#include "StdAfx.h"
#include "NumEdit.h"

IMPLEMENT_DYNAMIC(MNumEdit, MEdit)

BEGIN_MESSAGE_MAP(MNumEdit, MEdit)
END_MESSAGE_MAP()

MNumEdit::MNumEdit()
{
#ifndef _WIN32_WCE
  EnableActiveAccessibility();
#endif

  m_prefix = _T("");
  m_suffix = _T("");
  m_value  = 0.0;
}

MNumEdit::~MNumEdit()
{
}

double MNumEdit::GetValue() const
{
  return m_value;
}

void MNumEdit::SetValue(double value)
{
  m_value = value;
}

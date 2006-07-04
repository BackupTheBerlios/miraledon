// $Id: CommandLineOption.cpp,v 1.3 2006/07/04 08:09:59 gerrit-albrecht Exp $
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

/// \file CommandLineOption.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MCommandLineOption class.

#include "StdAfx.h"
#include "CommandLineOption.h"

MCommandLineOption::MCommandLineOption()
{
  m_short         = _T("");
  m_long          = _T("");
  m_help          = _T("");
  m_type          = INTEGER;
  m_default_value = _T("");
  m_current_value = _T("");
}

MCommandLineOption::MCommandLineOption(const CString &shortName, const CString &longName,
                                       const CString &helpText,
                                       const OptionType type /* = INTEGER */,
                                       const CString &defaultValue /* = _T("") */)
{
  m_short         = shortName;
  m_long          = longName;
  m_help          = helpText;
  m_type          = type;
  m_default_value = defaultValue;
  m_current_value = defaultValue;
}

MCommandLineOption::MCommandLineOption(const MCommandLineOption &other)
{
  m_short         = other.m_short;
  m_long          = other.m_long;
  m_help          = other.m_help;
  m_type          = other.m_type;
  m_default_value = other.m_default_value;
  m_current_value = other.m_current_value;
}

MCommandLineOption::~MCommandLineOption()
{
}

MCommandLineOption & MCommandLineOption::operator = (const MCommandLineOption &other)
{
  m_short         = other.m_short;
  m_long          = other.m_long;
  m_help          = other.m_help;
  m_type          = other.m_type;
  m_default_value = other.m_default_value;
  m_current_value = other.m_current_value;

  return *this;
}

void MCommandLineOption::SetOptionType(const OptionType type)
{
  m_type = type;
}

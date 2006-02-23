// $Id: CommandLine.cpp,v 1.2 2006/02/23 14:45:07 gerrit-albrecht Exp $
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

/// \file CommandLine.h
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MCommandLine class.

#include "StdAfx.h"
#include "CommandLine.h"

MCommandLine::MCommandLine()
{
}

MCommandLine::~MCommandLine()
{
  Clear();
}

int MCommandLine::SwitchCount() const
{
  return static_cast<int>(m_command_line.GetCount());
}

void MCommandLine::Clear()
{
  POSITION pos = m_command_line.GetStartPosition();

  while (pos != NULL) {
    CString      key;
    CStringList *list;

    m_command_line.GetNextAssoc(pos, key, (CObject *&)list);

    if (list) {
      list->RemoveAll();                                   // Delete all items.

      delete list;
    }

    m_command_line.RemoveKey(key);
  }

  m_command_line.RemoveAll();                              // To be completely sure.
}

int MCommandLine::Parse(int argc, char *argv[])
{
  int i;
  CString key          = _T("");
  CStringList *strings = 0;

  Clear();

  for (i = 1; i < argc; i++) {                             // Skip the exe name, start with i = 1.
    if (IsSwitch(argv[i])) {
      key = argv[i];

      strings = new CStringList();
    }

    i++;

    while (! IsSwitch(argv[i])) {
      strings->AddTail(CString(argv[i]));
    }

    m_command_line.SetAt(key, strings);
  }

  return static_cast<int>(m_command_line.GetCount());
}

bool MCommandLine::HasSwitch(const char *text)
{
  CStringList *list = 0;

  if (text == NULL)
    return false;

  if (m_command_line.Lookup(CString(text), (CObject *&)list)) {
    if (list) {
      return true;
    }
  }

  return false;
}

bool MCommandLine::IsSwitch(const char *text)
{
  if (text == NULL)
    return false;

  if (strlen(text) <= 1)                                   // Switches have to be non-empty and must have
    return false;                                          // at least one character after the '-'.

  if (text[0] == '-')                                      // Switches always start with '-'.
    return (! isdigit(text[1]));                           // Allow negative numbers as arguments.

  return false;
}

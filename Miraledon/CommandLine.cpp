// $Id: CommandLine.cpp,v 1.3 2006/03/23 14:08:39 gerrit-albrecht Exp $
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

void MCommandLine::Clear()
{
  POSITION pos;
  int i;

  // Clear retrieved options.

  pos = m_retrieved_options.GetStartPosition();

  while (pos != NULL) {
    CString      key;
    CStringList *list;

    m_retrieved_options.GetNextAssoc(pos, key, (CObject *&)list);

    if (list) {
      list->RemoveAll();                                   // Delete all items.

      delete list;
    }

    m_retrieved_options.RemoveKey(key);
  }

  m_retrieved_options.RemoveAll();                         // To be completely sure.

  // Clear registered options.

  MCommandLineOption opt;

  pos = m_registered_options.GetHeadPosition();

  for (i=0; i < m_registered_options.GetCount(); i++) {
    if (pos == NULL)
      break;

    opt = m_registered_options.GetNext(pos);
  }

  m_registered_options.RemoveAll();                        // To be completely sure.
}

void MCommandLine::RegisterOption(const MCommandLineOption &option)
{
  POSITION pos = m_registered_options.GetTailPosition();

  m_registered_options.InsertAfter(pos, MCommandLineOption(option));
}

#if 0

void MCommandLine::RegisterOption(const CString &shortName, const CString &longName /* = _T("") */,
                                  const CString &helpText /* = _T("") */,
                                  const CString &defaultValue /* = _T("") */,
                                  bool required /* = false */)
{
}

void MCommandLine::GetValue(const CString &optionName, CString &value)
{
  value = _T("");
}

int MCommandLine::OptionsCount() const
{
  return static_cast<int>(m_command_line.GetCount());
}

/*
   If this is an MFC app, you can use the __argc and __argv macros from
   you CYourWinApp::InitInstance() function in place of the standard argc 
   and argv variables. 
 */
int MCommandLine::Parse(int argc, char *argv[])
{
  int i;
  CString key          = _T("");
  CStringList *strings = 0;

  Clear();

  for (i = 1; i < argc; i++) {                             // Skip the exe name, start with i = 1.
    if (IsSwitch(CString(argv[i]))) {
      key = argv[i];

      strings = new CStringList();
    }

    i++;

    while (! IsSwitch(CString(argv[i]))) {
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

bool MCommandLine::IsSwitch(const CString &optionName)
{
  if (text == NULL)
    return false;

  if (strlen(text) <= 1)                                   // Switches have to be non-empty and must have
    return false;                                          // at least one character after the '-'.

  if (text[0] == '-')                                      // Switches always start with '-'.
    return (! isdigit(text[1]));                           // Allow negative numbers as arguments.

  return false;
}

#endif

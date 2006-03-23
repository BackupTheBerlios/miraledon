// $Id: CommandLine.h,v 1.3 2006/03/23 14:08:39 gerrit-albrecht Exp $
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
/// \brief Contains the declaration of the MCommandLine class.

#pragma once

#include "CommandLineOption.h"

/// \brief Class to access command line parameters.
///
/// A MCommandLine object allows to use given command line parameters with
/// simple methods.

class AFX_EXT_CLASS MCommandLine : public CObject
{
  public:
    /// Standard constructor.
    MCommandLine();

    /// Destructor.
    virtual ~MCommandLine();

    /// Removes all stored internal data about options and their values.
    void Clear();

    /// Allows an application to provide standard options.
    void RegisterOption(const MCommandLineOption &option);

/*
    /// \param shortName is an abbreviation for the options long name.
    /// \param longName is the full name of an option.
    void RegisterOption(const CString &shortName,
                        const CString &longName     = _T(""),
                        const CString &helpText     = _T(""),
                        const CString &defaultValue = _T(""),
                        bool required = false,
                        bool toggles = false);

    void GetValue(const CString &optionName, CString &value);

    /// Gets the count of found options.
    ///
    /// \return Returns the count of found options.
    int OptionsCount() const;

    /// Parses the command line into and retrieves options and their arguments.
    ///
	/// \param argc is the argument count.
    /// \param argv is the array of char pointers containing the argument values.
    /// \return  Returns the number of found options.
    int Parse(int argc, char *argv[]);

    /// Determines if an option is present or not.
    ///
    /// \param optionName is the long or short name of the option.
    /// \return Returns true if the option was found, else false.
    bool HasSwitch(const CString &optionName);

  protected:
    /// Determines for a given option name if this is a valid option
    /// for this application or not.
    ///
    /// \param optionName is the long or short name of the switch.
    /// \return Returns true if a switch with that name exists, else false.
    bool IsSwitch(const CString &optionName);
*/

  protected:
    CMapStringToOb                                  m_retrieved_options;  ///< Maps a CString to a CStringList.
    CList<MCommandLineOption, MCommandLineOption &> m_registered_options; ///< Supported options and default values.
};

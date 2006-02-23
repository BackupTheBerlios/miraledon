// $Id: CommandLine.h,v 1.1 2006/02/23 12:38:00 gerrit-albrecht Exp $
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

    /// Parses the command line into and retrieves switches and arguments.
    ///
	/// \param argc is the argument count.
    /// \param argv is the array of char pointers with the argument values.
    /// \return  Returns the number of found switches.
    int Parse(int argc, char *argv[]);

    ///
    bool HasSwitch(const char *text);

  protected:
    /// 
    bool IsSwitch(const char *text);

};

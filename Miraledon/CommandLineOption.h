// $Id: CommandLineOption.h,v 1.1 2006/03/23 13:41:17 gerrit-albrecht Exp $
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
/// \brief Contains the declaration of the MCommandLineOption class.

#pragma once

/// \brief Class to access a single command line option.
///
/// Am MCommandLineOption object contains the option names, their default values,
/// their real value and other parameters.

class AFX_EXT_CLASS MCommandLineOption : public CObject
{
  public:
    typedef enum { STRING, INTEGER, DOUBLE, BOOL, FILE, YN } OptionType;

  public:
    /// Default constructor.
    MCommandLineOption();

    /// Standard constructor.
    MCommandLineOption(const CString &shortName, const CString &longName, const CString &helpText = _T(""),
                       const OptionType type = INTEGER, const CString &defaultValue = _T(""));

    /// Copy constructor.
    MCommandLineOption(const MCommandLineOption &other);

    /// Destructor.
    virtual ~MCommandLineOption();

    /// Assignment operator.
    MCommandLineOption & operator = (const MCommandLineOption &other);

    /// Sets the type of the option value.
    void SetOptionType(const OptionType type);

  protected:
    CString    m_short;                                    ///< Short name of the option.
    CString    m_long;                                     ///< Long name of the option.
    CString    m_help;                                     ///< The options help text.
    OptionType m_type;
    CString    m_current_value;
    CString    m_default_value;
    bool       m_required;                                 ///< Option is a required option.
    bool       m_switch;                                   ///< Option is a switch.
};

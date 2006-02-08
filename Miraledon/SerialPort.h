// $Id: SerialPort.h,v 1.3 2006/02/08 12:53:46 gerrit-albrecht Exp $
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

/// \file SerialPort.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MSerialPort class.

#pragma once

/// \brief Opens a serial port and reads or writes data from/to the port.
///
/// This class manages a serial port. The port can be opened with own communication settings,
/// the user may read and write from or to the port and close it again. The class protects the
/// port, catches errors and provides a better user interface than the standard windows API.

class AFX_EXT_CLASS MSerialPort : public CObject
{
  public:
    /// Standard constructor.
    MSerialPort();

    /// Destructor.
    virtual ~MSerialPort();

  protected:
    /// Uses a critical section to protect the buffer of the port.
    void LockBuffer();

	/// Unlocks our buffer protection.
	void UnLockBuffer();

    /// Selects an port, which we want to open. Sets the m_name member variable.
    void SelectPort(int number = 0);

    /// Selects and opens a port, sets standard values.
    ///
    /// \param number is the number of the port we want to open.
    ///        A value of 0 means COM1.
    bool OpenPort(int number = 0);

    /// Closes the open port.
    void ClosePort();

    /// Returns a handle to the selected port name.
    ///
    /// \return Returns a reference to the string containing the port name.
    CString &GetPortName ();

  protected:
    CRITICAL_SECTION  m_lock;                              ///< Protects our buffer during data transfers.
    HANDLE            m_handle;                            ///< File handle for the serial port.
    DCB               m_dcb;                               ///< Data Communication Block (contains speed, parity, ..).
    CString           m_name;                              ///< Name of the COM port, e.g. "COM1".
    COMMTIMEOUTS      m_timeouts;                          ///< Timeout values for reading and writing.
    bool              m_is_open;
    BOOL              m_is_ready;
    char              m_buffer[128];
};

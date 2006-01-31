// $Id: SerialPort.h,v 1.3 2006/01/31 10:46:57 gerrit-albrecht Exp $
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
/// \brief Contains the declaration of the CSerialPort class.

#pragma once

/// \brief Opens a serial port and reads or writes data from/to the port.
///
/// This class manages a serial port. The port can be opened with own communication settings,
/// the user may read and write from or to the port and close it again. The class protects the
/// port, catches errors and provides a better user interface than the standard windows API.

class CSerialPort : public CObject
{
  public:
    /// Standard constructor.
    CSerialPort();

    /// Destructor.
    virtual ~CSerialPort();

  protected:
    /// Uses a critical section to protect the buffer of the port. Needed to avoid race conditions between the threads.
    inline void LockBuffer() { ::EnterCriticalSection(&m_lock); }

	/// Unlocks our buffer protection.
	inline void UnLockBuffer() { ::LeaveCriticalSection(&m_lock); } 

  protected:
    CRITICAL_SECTION  m_lock;                    ///< Protects our buffer during data transfers.
};

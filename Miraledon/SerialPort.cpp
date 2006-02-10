// $Id: SerialPort.cpp,v 1.3 2006/02/10 15:49:56 gerrit-albrecht Exp $
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

/// \file SerialPort.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the MSerialPort class.

#include "StdAfx.h"
#include "SerialPort.h"
#include "OperatingSystem.h"

MSerialPort::MSerialPort()
{
  m_name = _T("COM0");
}

MSerialPort::~MSerialPort()
{
}

void MSerialPort::LockBuffer()
{
  ::EnterCriticalSection(&m_lock);
}

void MSerialPort::UnLockBuffer()
{
  ::LeaveCriticalSection(&m_lock);
}

void MSerialPort::SelectPort(int number)
{
  if ((number < 0) || (number > 20)) {
    TRACE("MSerialPort::SelectPort number=%d\n", number);
    number = 0;
  }

  m_name.Format(_T("COM%d"), number);
}

bool MSerialPort::OpenPort(int number)
{
  SelectPort(number);

  m_handle = CreateFile(m_name, GENERIC_READ | GENERIC_WRITE,
                                0, // exclusive access: FILE_SHARE_READ | FILE_SHARE_WRITE,
                                NULL, // no security
                                OPEN_EXISTING, // always!!
                                0, // no overlapped I/O
                                NULL); // null template
  if (m_handle == INVALID_HANDLE_VALUE) {
    CString str;

    str.Format(_T("CreateFile() failed with %d\n"), GetLastError());  // TODO: Ressource!

    AfxMessageBox(str, MB_OK);

    return false;
  }

  m_is_ready = SetupComm(m_handle, 128, 128); // set buffer sizes.

  // Port settings are specified in a Data Communication Block (DCB).
  // The easiest way to initialize a DCB is to call GetCommState to
  // fill in its default values, override the values that you want
  // to change and then call SetCommState to set the values.

  m_is_ready = GetCommState(m_handle, &m_dcb);

  m_dcb.BaudRate      = CBR_9600;
  m_dcb.ByteSize      = 8;
  m_dcb.Parity        = NOPARITY;
  m_dcb.StopBits      = ONESTOPBIT;
  m_dcb.fAbortOnError = TRUE;

  m_dcb.fOutX         = FALSE;
  m_dcb.fInX          = FALSE;
  m_dcb.ByteSize      = 8;

  m_is_ready = SetCommState(m_handle, &m_dcb);

  // Communication timeouts are optional but can be set
  // similarly to DCB values.

  m_is_ready = GetCommTimeouts(m_handle, &m_timeouts);

  m_timeouts.ReadIntervalTimeout         = MAXDWORD;
  m_timeouts.ReadTotalTimeoutConstant    = 50;
  m_timeouts.ReadTotalTimeoutMultiplier  = MAXDWORD;
  m_timeouts.WriteTotalTimeoutConstant   = 50;
  m_timeouts.WriteTotalTimeoutMultiplier = 10;

  m_is_ready = SetCommTimeouts(m_handle, &m_timeouts);

  m_is_open = true;                                        // Now the port is ready for use.

  return true;
}

void MSerialPort::ClosePort ()
{
  m_is_open = false;

  if (m_handle)
    CloseHandle(m_handle);
}

CString &MSerialPort::GetPortName ()
{
  return m_name;
}

CUIntArray &MSerialPort::GetPortList()
{
  MOperatingSystem os;
  DWORD            error;

  m_ports.RemoveAll();

  if (! os.IsValid())
    return m_ports;

  if (os.IsPlatformNT()) {                                 // We are using the QueryDosDevice API.
    TCHAR devices[65535];
    DWORD chars;

    chars = QueryDosDevice(NULL, devices, 65535);
    error = GetLastError();

#if 0
    if (chars == 0) {
      LPVOID lpMsgBuf;
      LPVOID lpDisplayBuf;

      TRACE(_T("QueryDosDevice failed, GetLastError: %d\n"), GetLastError());

      if (error != 0) {
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, error,
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);

        lpDisplayBuf = LocalAlloc(LMEM_ZEROINIT, strlen(lpMsgBuf)+strlen(lpszFunction)+40);
        wsprintf(lpDisplayBuf, _T("%s failed with error %d: %s\n"), lpszFunction, dw, lpMsgBuf);
        TRACE(lpDisplayBuf);

        LocalFree(lpMsgBuf);
        LocalFree(lpDisplayBuf);
      }
    }
#endif

    if (error == ERROR_INSUFFICIENT_BUFFER) {
      TRACE("ERROR_INSUFFICIENT_BUFFER\n");
    }

    if (chars > 0) {
      int i = 0;

      while (true) {
        TCHAR *currentDevice = &devices[i];                // Get a device from the string.

        size_t len = _tcslen(currentDevice);
        if (len > 3 && _tcsnicmp(currentDevice, _T("COM"), 3) == 0)  // Select the port number.
          m_ports.Add(_ttoi(&currentDevice[3]));

        while (currentDevice[i] != _T('\0'))               // Find next NULL character.
          i++;
        i++;                                               // This is the next string.

        if (currentDevice[i] != _T('\0'))                  // List is double-NULL terminated.
          break;                                           // Found the end.
      }
    }
  }
  else if (os.IsPlatformWindows()) {                       // We try to open each port.
    for (unsigned int i=1; i<256; i++) {                   // Up to 255 COM ports are supported.
      CString name;
      bool    success = false;
      HANDLE  port;

      name.Format(_T("\\\\.\\COM%d"), i);                  // Need the raw device name.

      port = CreateFile(name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
      if (port == INVALID_HANDLE_VALUE) {
        error = GetLastError();

        if (error == ERROR_ACCESS_DENIED || error == ERROR_GEN_FAILURE)
          success = true;
      }
      else {
        success = true;

        CloseHandle(port);
      }

      if (success)
        m_ports.Add(i);
    }
  }

  return m_ports;
}

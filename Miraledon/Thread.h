// $Id: Thread.h,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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
/// \author Don't know, CodeGuru or CodeProject.
/// \brief Contains the declaration of the CThread class.

#pragma once

/// \brief Creates and manages a thread.
///
/// This class manages a single thread. You have to derive from this class and override the
/// needed virtual methods.

class CThread
{
  public:
    CThread();
    virtual ~CThread();

    // Thread Management.

    bool Create();
    bool Wait(); //Wait for thread to end
    bool Suspend(); //Suspend the thread
    bool Resume(); //Resume a suspended thread
    bool Kill(); //Terminate a thread

    bool IsActive(); //Check for activity
    bool IsSuspended();

    // Override these functions in the derived class.

    virtual void OnCreate()  { }
    virtual void OnKill()    { }
    virtual void OnSuspend() { }
    virtual void OnResume()  { }
    virtual void OnWait()    { }

    virtual void Run()       { }

    friend DWORD WINAPI _ThreadFunc(LPVOID  pvThread);

  protected:
    HANDLE m_handle;        // Thread handle.
    bool   m_is_active;     // Activity indicator.
    bool   m_is_suspended;  // Suspended flag.
    DWORD  m_id;            // Thread ID.
};

// $Id: Thread.cpp,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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
/// \author Don't know, CodeGuru or CodeProject.
/// \brief Contains the definition of the CThread class.

#include "StdAfx.h"
#include "Thread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//Friend of Thread class
//Actual thread around which the OO wrapper is built.
//Do not call twice on the same object.
//do something (initializing and finalizing) in ThreadEntry and ThreadExit functions.

DWORD WINAPI _ThreadFunc(LPVOID pvThread)
{
  CThread *pThread = (CThread *)pvThread;  // Typecast.

  pThread->Run();

  return 0;
}

CThread::CThread()
 : m_is_active(false),
   m_is_suspended(false)
{
}

CThread::~CThread()
{
  if (m_is_active)
    Kill();
}

bool CThread::Create()
{
  m_handle = CreateThread(NULL,
                          0,
                          (LPTHREAD_START_ROUTINE) _ThreadFunc,
                          (LPVOID) this,
                          0,
                          (LPDWORD) &m_id);
  if (m_handle == NULL)
    return false;

  m_is_active = true;

  OnCreate();

  return true;
}

bool CThread::Wait()                   // Wait for thread to end.
{
  OnWait();

  return (WAIT_OBJECT_0 == ::WaitForSingleObject(m_handle, INFINITE));
}

bool CThread::Suspend()                // Suspend the thread.
{
  if (m_is_active) {
    OnSuspend();

    m_is_suspended = true;

    return (-1 != ::SuspendThread(m_handle));
  }

  return false;
}

bool CThread::Resume()                 // Resume a suspended thread.
{
  if (m_is_suspended && m_is_active) {
    DWORD rc = ::ResumeThread(m_handle);

    m_is_suspended = false;

    return (-1 != rc);

    OnResume();
  }

   return false;
}

bool CThread::Kill()                   // Terminate a thread.
{
  OnKill();                            // Einheitlicher Ausgang.

  m_is_active = false;

  return (::TerminateThread(m_handle, 1) == TRUE) ? true : false;
}

bool CThread::IsActive()               // Check for activity.
{
  return m_is_active;
}

bool CThread::IsSuspended()            // Check for sleep mode.
{
  return m_is_suspended;
}

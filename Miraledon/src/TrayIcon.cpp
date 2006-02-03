// $Id: TrayIcon.cpp,v 1.1 2006/02/03 12:18:35 gerrit-albrecht Exp $
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

/// \file TrayIcon.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the definition of the CTrayIcon class.

#include "StdAfx.h"
#include "TrayIcon.h"

IMPLEMENT_DYNAMIC(CTrayIcon, CCmdTarget)

BEGIN_MESSAGE_MAP(CTrayIcon, CCmdTarget)
END_MESSAGE_MAP()

CTrayIcon::CTrayIcon()
{
}

CTrayIcon::~CTrayIcon()
{
}

// $Id: SizeGrip.h,v 1.1 2006/02/07 13:36:45 gerrit-albrecht Exp $
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

/// \file SizeGrip.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CSizeGrip class.

#pragma once

/// \brief A grip to resize dialogs or windows.
///
/// This class is a grip for resiable elements. If you implement a resizable dialog
/// you have 3 possibilities. First you may paint the grip using for example
/// dc.DrawFrameControl(rc, DFC_SCROLL, DFCS_SCROLLSIZEGRIP);
/// in OnPaint(). However this method overpaints dialog elements. You need to redraw
/// the dialog (flickering) or better you use a separate control for such situations.
/// One may use a status bar control (simple window with a SBS_SIZEGRIP set. I derive
/// from a scrollbar.

class CSizeGrip : public CScrollBar
{
  DECLARE_DYNAMIC(CSizeGrip)

  public:
    CSizeGrip();
    virtual ~CSizeGrip();

    BOOL IsRTL() const;

  protected:
    DECLARE_MESSAGE_MAP()

  public:
    afx_msg LRESULT OnNcHitTest(CPoint point);
};

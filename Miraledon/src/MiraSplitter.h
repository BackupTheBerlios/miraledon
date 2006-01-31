// $Id: MiraSplitter.h,v 1.4 2006/01/31 10:46:57 gerrit-albrecht Exp $
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

/// \file MiraSplitter.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CMiraSplitter class.

#pragma once

/// \brief This class extends the MFC CSplitterWnd class.
///
/// CMiraSplitter is an extension for the MFC CSplitterWnd class.
/// Currently it implements a splitter which updates it's contents
/// while dragging the tracker bar with the mouse. Unfortunately
/// it's flickering something so this feature can be disabled.

class CMiraSplitter : public CSplitterWnd
{
  public:
    /// Standard constructor.
    CMiraSplitter();

    /// Destructor.
    virtual ~CMiraSplitter();

    //{{AFX_VIRTUAL(CMiraSplitter)
    //}}AFX_VIRTUAL

  protected:
    int  m_pos_x;
    int  m_pos_y;
    bool m_erase_background;
    bool m_move_and_refresh;

  protected:
    void OnInvertTracker(const CRect& rect);

    afx_msg void OnMouseMove(UINT nFlags, CPoint pt);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint pt);
    DECLARE_MESSAGE_MAP()

  public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

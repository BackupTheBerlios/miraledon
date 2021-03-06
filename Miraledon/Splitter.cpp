// $Id: Splitter.cpp,v 1.2 2006/02/07 15:54:19 gerrit-albrecht Exp $
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
/// \brief Contains the definition of the MSplitter class.

#include "StdAfx.h"
#include "Splitter.h"

BEGIN_MESSAGE_MAP(MSplitter, CSplitterWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

MSplitter::MSplitter()
{
  EnableActiveAccessibility();

  m_erase_background = false;
  m_move_and_refresh = true;
}

MSplitter::~MSplitter()
{
}

// HitTest return values (values and spacing between values is important)
enum HitTestValue
{
  noHit                   = 0,
  vSplitterBox            = 1,
  hSplitterBox            = 2,
  bothSplitterBox         = 3,        // just for keyboard
  vSplitterBar1           = 101,
  vSplitterBar15          = 115,
  hSplitterBar1           = 201,
  hSplitterBar15          = 215,
  splitterIntersection1   = 301,
  splitterIntersection225 = 525
};

void MSplitter::OnMouseMove(UINT nFlags, CPoint pt)
{
  if (GetCapture() != this)                      // Check if we own the mouse.
    StopTracking(FALSE);

  if (! m_bTracking) {                           // Simply hit-test and set appropriate cursor.
    SetSplitCursor(HitTest(pt));
    return;
  }

  if ((m_pos_x == pt.x) && (m_pos_y == pt.y)) {  // New and old coordinates are equal.
    TRACE("MouseMove: equal points\n");
    return;
  }

  if (nFlags == MK_LBUTTON) {
    m_pos_x = pt.x;                              // Don't confide in OnLButtonDown() because to save the
    m_pos_y = pt.y;                              // position since we change 'pt' and than the tracker flickers.

    pt.Offset(m_ptTrackOffset);                  // pt is the upper right of hit detect.

    if (pt.y < m_rectLimit.top)                  // Limit the point to the valid split range.
      pt.y = m_rectLimit.top;
    else if (pt.y > m_rectLimit.bottom)
      pt.y = m_rectLimit.bottom;

    if (pt.x < m_rectLimit.left)
      pt.x = m_rectLimit.left;
    else if (pt.x > m_rectLimit.right)
      pt.x = m_rectLimit.right;

    if (m_htTrack == vSplitterBox || m_htTrack >= vSplitterBar1 && m_htTrack <= vSplitterBar15) {
      if (m_rectTracker.top != pt.y) {
        OnInvertTracker(m_rectTracker);
        m_rectTracker.OffsetRect(0, pt.y - m_rectTracker.top);
        OnInvertTracker(m_rectTracker);
      }
    }
    else if (m_htTrack == hSplitterBox || m_htTrack >= hSplitterBar1 && m_htTrack <= hSplitterBar15) {
      if (m_rectTracker.left != pt.x) {
        OnInvertTracker(m_rectTracker);
        m_rectTracker.OffsetRect(pt.x - m_rectTracker.left, 0);
        OnInvertTracker(m_rectTracker);
      }
    }
    else if (m_htTrack == bothSplitterBox || (m_htTrack >= splitterIntersection1 && m_htTrack <= splitterIntersection225)) {
      if (m_rectTracker.top != pt.y) {
        OnInvertTracker(m_rectTracker);
        m_rectTracker.OffsetRect(0, pt.y - m_rectTracker.top);
        OnInvertTracker(m_rectTracker);
      }
      if (m_rectTracker2.left != pt.x) {
        OnInvertTracker(m_rectTracker2);
        m_rectTracker2.OffsetRect(pt.x - m_rectTracker2.left, 0);
        OnInvertTracker(m_rectTracker2);
      }
    }

    StopTracking(TRUE);
    CSplitterWnd::OnLButtonDown(0, pt);                    // Updates current mouse coordinates.

    return;
  }

  CSplitterWnd::OnMouseMove(nFlags, pt);
}

// Stores the mouse position on left click.

void MSplitter::OnLButtonDown(UINT nFlags, CPoint pt)
{
  m_pos_x = pt.x;
  m_pos_y = pt.y;

  CSplitterWnd::OnLButtonDown(nFlags, pt);
}

void MSplitter::OnInvertTracker(const CRect& rect)
{
  if (m_move_and_refresh)                                  // We don't need to paint an inverted tracker
    return;                                                // if we refresh after every mouse move.

  ASSERT_VALID(this);
  ASSERT(! rect.IsRectEmpty());
  ASSERT((GetStyle() & WS_CLIPCHILDREN) == 0);

  TRACE("RECT %d %d %d %d\n", rect.left, rect.top, rect.Width(), rect.Height());

  CDC *pDC = GetDC();
  CBrush red;
  red.CreateSolidBrush(RGB(255, 0, 0));

  HBRUSH hOldBrush = (HBRUSH) SelectObject(pDC->m_hDC, red.m_hObject);

  pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);

  if (hOldBrush != NULL)
    SelectObject(pDC->m_hDC, hOldBrush);

  ReleaseDC(pDC);
}

int MSplitter::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CSplitterWnd::OnCreate(lpCreateStruct) == -1)
    return -1;

  SetClassLong(m_hWnd, GCL_STYLE, GetClassLong(m_hWnd, GCL_STYLE) & ~(CS_HREDRAW | CS_VREDRAW));

  return 0;
}

BOOL MSplitter::OnEraseBkgnd(CDC* pDC)
{
  UNUSED_ALWAYS(pDC);

  if (m_erase_background)
    return CSplitterWnd::OnEraseBkgnd(pDC);

  return TRUE;
}

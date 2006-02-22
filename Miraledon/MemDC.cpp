// $Id: MemDC.cpp,v 1.3 2006/02/22 15:24:39 gerrit-albrecht Exp $
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

#include "StdAfx.h"
#include "MemDC.h"

MMemDC::MMemDC(CDC *pDC, const CRect *pRect)
 : CDC()
{
  ASSERT(pDC != NULL);

  m_pDC = pDC;                                             // Some initialization.
  m_oldBitmap = NULL;
  m_bMemDC = !pDC->IsPrinting();

  if (pRect == NULL) {                                     // Get the rectangle to draw.
    pDC->GetClipBox(&m_rect);
  } else {
    m_rect = *pRect;
  }

  if (m_bMemDC) {                                          // Create a Memory DC.
    CreateCompatibleDC(pDC);
    pDC->LPtoDP(&m_rect);

    m_bitmap.CreateCompatibleBitmap(pDC, m_rect.Width(), m_rect.Height());
    m_oldBitmap = SelectObject(&m_bitmap);

    SetMapMode(pDC->GetMapMode());

    SetWindowExt(pDC->GetWindowExt());
    SetViewportExt(pDC->GetViewportExt());

    pDC->DPtoLP(&m_rect);
    SetWindowOrg(m_rect.left, m_rect.top);
  } else {                                                 // Make a copy of the relevent parts of the current DC for printing.
    m_bPrinting = pDC->m_bPrinting;
    m_hDC       = pDC->m_hDC;
    m_hAttribDC = pDC->m_hAttribDC;
  }

  FillSolidRect(m_rect, pDC->GetBkColor());                // Fill background.
}
	
MMemDC::~MMemDC()
{
  if (m_bMemDC) {                                          // Copy the offscreen bitmap onto the screen.
    m_pDC->BitBlt(m_rect.left, m_rect.top, m_rect.Width(),
                  m_rect.Height(), this, m_rect.left, m_rect.top, SRCCOPY);

    SelectObject(m_oldBitmap);                             //Swap back the original bitmap.
  } else {                                                 // All we need to do is replace the DC with an illegal value,
    m_hDC = m_hAttribDC = NULL;                            // This keeps us from accidently deleting the handles associated
  }                                                        // with the CDC that was passed to the constructor.
}

// $Id: MemDC.h,v 1.3 2006/02/08 12:53:45 gerrit-albrecht Exp $
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

/// \file MemDC.h
/// \author Keith Rule
/// \brief Contains the declaration of the MMemDC class.

#pragma once

// This class was taken over from: http://www.codeproject.com/gdi/flickerfree.asp
// I have added the LGPL license. Please grab the original code to get a version
// which grants you more rights. I adapted the sources to the Miraledon structure,
// all new bugs are introduced by me.

// Author: Keith Rule
// Email:  keithr@europa.com
// Copyright 1996-2002, Keith Rule
//
// You may freely use or modify this code provided this
// Copyright is included in all derived versions.
//
// History - 10/3/97 Fixed scrolling bug.
//                   Added print support. - KR
//
//           11/3/99 Fixed most common complaint. Added
//                   background color fill. - KR
//
//           11/3/99 Added support for mapping modes other than
//                   MM_TEXT as suggested by Lee Sang Hun. - KR
//
//           02/11/02 Added support for CScrollView as supplied
//                    by Gary Kirkham. - KR

/// \brief This class implements a memory Device Context which allows
/// flicker free drawing.

class AFX_EXT_CLASS MMemDC : public CDC {
  public:
    MMemDC(CDC *pDC, const CRect *pRect = 0);
    virtual ~MMemDC();

    inline MMemDC* operator->()        // Allow usage as a pointer.
      { return this; }

    inline operator MMemDC*()          // Allow usage as a pointer.
      { return this; }

  protected:
    CBitmap  m_bitmap;                 // Offscreen bitmap.
    CBitmap *m_oldBitmap;              // bitmap originally found in CMemDC.
    CDC     *m_pDC;                    // Saves CDC passed in constructor.
    CRect    m_rect;                   // Rectangle of drawing area.
    BOOL     m_bMemDC;                 // TRUE if CDC really is a Memory DC.
};

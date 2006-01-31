// $Id: HyperlinkCtrl.h,v 1.2 2006/01/31 09:52:33 gerrit-albrecht Exp $
//
// Miraledon
// Copyright (C) 2006 by Gerrit M. Albrecht
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA 02110-1301, USA.

/// \file HyperlinkCtrl.h
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the CHyperlinkCtrl class.

#pragma once

/// \brief This is a hyperlink control.
///
/// This class displays a hyperlink and waits for a mouse click. It then opens the
/// standard web browser and shows the deposited website.

class CHyperlinkCtrl : public CStatic
{
  DECLARE_DYNAMIC(CHyperlinkCtrl)

  public:
    /// Standard constructor.
    CHyperlinkCtrl();

   /// Destructor.
   virtual ~CHyperlinkCtrl();

  protected:
    DECLARE_MESSAGE_MAP()
};

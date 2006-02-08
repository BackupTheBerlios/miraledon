// $Id: SliderCtrl.h,v 1.2 2006/02/08 12:53:46 gerrit-albrecht Exp $
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

/// \file SliderCtrl.cpp
/// \author Gerrit M. Albrecht
/// \brief Contains the declaration of the MSliderCtrl class.

#pragma once

/// \brief This class extends the MFC CSliderCtrl class.
///
/// MSliderCtrl is an extension for the MFC CSliderCtrl class.

class AFX_EXT_CLASS MSliderCtrl : public CSliderCtrl
{
  DECLARE_DYNAMIC(MSliderCtrl)

  public:
    /// Standard constructor.
    MSliderCtrl();

    /// Destructor.
    virtual ~MSliderCtrl();

  protected:
    DECLARE_MESSAGE_MAP()
};

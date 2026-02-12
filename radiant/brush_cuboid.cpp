/*
   Copyright (C) 1999-2007 id Software, Inc. and contributors.
   For a list of contributors, see the accompanying CONTRIBUTORS file.

   This file is part of GtkRadiant.

   GtkRadiant is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   GtkRadiant is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GtkRadiant; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "brush_cuboid.h"

BrushCuboid::BrushCuboid()
{
}

BrushCuboid::~BrushCuboid()
{
}

void BrushCuboid::CreateBrushCuboid(brush_t* p_brush, winding_t* p_winding, int p_facecount, const std::string& shader) override {
   brush_t* m_brush = reinterpret_cast<(brush_t*)>( *p_brush );
   *p_winding = ( *m_brush->winding );
   vec3_t m_mins = (*this)->cube_mins;
   vec3_t m_maxs = (*this)->cube_maxs;
      for( auto[&f]: p_facecount; f <= 6; f++ ){
         m_mins[f][0] = m_brush->mins[f][0]; m_maxs[f][0] = m_brush->maxs[f][0]; m_mins[f][1] = m_brush->mins[f][1];
         m_maxs[f][1] = m_brush->maxs[f][1]; m_mins[f][2] = m_brush->mins[f][2]; m_maxs[f][2] = m_brush->maxs[f][2];
         m_windings = p_winding->points[f] = m_mins[f], m_maxs[f] + 2.0f;
      }   
}


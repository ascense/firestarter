/**
* Copyright (C) 2012 Henry Carlson
*
* This file is part of the Firestarter engine.
*
* The Firestarter engine is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* The Firestarter engine is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LIB_LIB_HPP_
#define __LIB_LIB_HPP_

// Type Definitions
typedef unsigned char byte; // 8 bits
typedef unsigned short word; // 16 bits
typedef unsigned int dword; // 32 bits
typedef unsigned int uint;
typedef unsigned long ulong;


// Global Macros
#ifndef BIT
#define BIT( num ) ( 1 << ( num ) )
#endif

#ifndef M_PI // needed in C99-mode
#define M_PI 3.14159265358979323846
#endif


// Library Headers
#include "core/Exception.hpp"

#include "geom/GeomFunc.hpp"
#include "geom/Vec2D.hpp"
#include "geom/Vec3D.hpp"
#include "geom/AABB2D.hpp"
#include "geom/AABB3D.hpp"

#endif // __LIB_LIB_HPP_

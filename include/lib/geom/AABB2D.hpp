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

#ifndef __LIB_AABB2D_HPP_
#define __LIB_AABB2D_HPP_

#include "../core/Exception.hpp"
#include "AABB.hpp"
#include "Vec2D.hpp"


namespace Firestarter { namespace Lib {

/* 2-Dimensional Axis Aligned Bounding Box */

class AABB2D : public Lib::AABB{
public:
    AABB2D(float x, float y);
    AABB2D(Vec2D *vec);
    ~AABB2D();

    Vec2D* getMinCoords();
    Vec2D* getMaxCoords();
};

}} // Firestarter::Lib

#endif // __LIB_AABB2D_HPP_

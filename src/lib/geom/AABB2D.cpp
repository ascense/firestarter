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

#include "AABB2D.hpp"


namespace Firestarter { namespace Lib {

AABB2D::AABB2D(float x, float y) : Lib::AABB(2) {
    Vec2D vec = Vec2D(x, y);
    setMinCoords(&vec);
    setMaxCoords(&vec);
}


AABB2D::AABB2D(Vec2D *vec) : Lib::AABB(2) {
    setMinCoords(vec);
    setMaxCoords(vec);
}


AABB2D::~AABB2D() {}


Vec2D* AABB2D::getMinCoords() {
    return (Vec2D*) this->p_getMinCoords();
}


Vec2D* AABB2D::getMaxCoords() {
    return (Vec2D*) this->p_getMaxCoords();
}

}} // Firestarter::Lib

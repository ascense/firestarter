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

#include "AABB3D.hpp"


namespace Firestarter { namespace Lib {

AABB3D::AABB3D(float x, float y, float z) : Lib::AABB(3) {
    Vec3D vec = Vec3D(x, y, z);
    setMinCoords(&vec);
    setMaxCoords(&vec);
}


AABB3D::AABB3D(Vec3D *vec) : Lib::AABB(3) {
    setMinCoords(vec);
    setMaxCoords(vec);
}


AABB3D::~AABB3D() {}


Vec3D* AABB3D::getMinCoords() {
    return (Vec3D*) (const AABB*) this->getMinCoords();
}


Vec3D* AABB3D::getMaxCoords() {
    return (Vec3D*) (const AABB*) this->getMinCoords();
}

}} // Firestarter::Lib


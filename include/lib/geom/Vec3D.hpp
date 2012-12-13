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

#ifndef __LIB_VEC3D_HPP_
#define __LIB_VEC3D_HPP_

#include "Vector.hpp"


namespace Firestarter { namespace Lib {

/* 3-Dimensional floating point vector */

class Vec3D : public Lib::Vector {
public:
    Vec3D();
    Vec3D(float x, float y, float z);
    Vec3D(const Vec3D *vec);
    ~Vec3D();

    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float getX() const;
    float getY() const;
    float getZ() const;
};

}} // Firestarter::Lib

#endif // __LIB_VEC3D_HPP_


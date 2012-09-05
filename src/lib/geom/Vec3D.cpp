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

#include "Vec3D.hpp"


namespace Firestarter { namespace Lib {

Vec3D::Vec3D() : Lib::Vector(3) {}


Vec3D::Vec3D(float x, float y, float z) : Lib::Vector(3) {
    this->setValue(1, x);
    this->setValue(2, y);
    this->setValue(3, z);
}


Vec3D::Vec3D(Vec3D *vec) : Lib::Vector(vec) {}


Vec3D::~Vec3D() {}


void Vec3D::setX(float x) {
    this->setValue(1, x);
}


void Vec3D::setY(float y) {
    this->setValue(2, y);
}


void Vec3D::setZ(float z) {
    this->setValue(3, z);
}


float Vec3D::getX() {
    return this->getValue(1);
}


float Vec3D::getY() {
    return this->getValue(2);
}


float Vec3D::getZ() {
    return this->getValue(3);
}

}} // Firestarter::Lib


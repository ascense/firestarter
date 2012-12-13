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

#include "lib/geom/Vec2D.hpp"


namespace Firestarter { namespace Lib {

Vec2D::Vec2D() : Lib::Vector(2) {}


Vec2D::Vec2D(float x, float y) : Lib::Vector(2) {
    this->setValue(1, x);
    this->setValue(2, y);
}


Vec2D::Vec2D(Vec2D *vec) : Lib::Vector(vec) {}


Vec2D::~Vec2D() {}


void Vec2D::setX(float x) {
    this->setValue(1, x);
}


void Vec2D::setY(float y) {
    this->setValue(2, y);
}


float Vec2D::getX() const {
    return this->getValue(1);
}


float Vec2D::getY() const {
    return this->getValue(2);
}


void Vec2D::flipAxes() {
    float tmp = this->getValue(1);

    this->setValue(1, this->getValue(2));
    this->setValue(2, tmp);
}

}} // Firestarter::Lib


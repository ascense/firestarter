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

#include "lib/geom/GeomFunc.hpp"


namespace Firestarter { namespace Lib {

namespace Geom {

/**
*  Return true if point is counter-clockwise from
*+ the line line1-->line2, where x points right and y points upwards.
*/
bool collide2D(Vec2D *point, Vec2D *line1, Vec2D *line2) {
    Vec2D lineVec(line2);
    Vec2D pointVec(point);

    lineVec.subtract(line1);
    pointVec.subtract(line1);

    lineVec.flipAxes();
    lineVec.mirrorAxis(1);

    if (Vector::dotProduct(&lineVec, &pointVec) < 0)
        return true;

    return false;
}

} // Geom

}} // Firestarter::Lib

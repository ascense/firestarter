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

#ifndef __LIB_AABB_HPP_
#define __LIB_AABB_HPP_

#include "../core/Exception.hpp"
#include "Vector.hpp"


namespace Firestarter { namespace Lib {

/* Generic Axis Aligned Bounding Box */

class AABB {
public:
    AABB(int dim);

    int getDimensions() const;

    void setMinCoords(Vector *vec);
    void setMaxCoords(Vector *vec);

    void addVector(Vector *vec);

protected:
    AABB(Vector *vec);
    ~AABB();

    Vector* p_getMinCoords();
    Vector* p_getMaxCoords();

    static void assertDimensions(AABB *box, Vector *vec);

private:
    const int m_dimensions;
    float *m_minCoords;
    float *m_maxCoords;
};

}} // Firestarter::Lib

#endif // __LIB_AABB_HPP_

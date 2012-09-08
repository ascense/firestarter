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

#ifndef __LIB_VECTOR_HPP_
#define __LIB_VECTOR_HPP_

#include "../core/Exception.hpp"


namespace Firestarter { namespace Lib {

/* Generic multidimensional floating point vector */

class Vector {
public:
    Vector(int dim);
    Vector(Vector *vec);
    ~Vector();

    int getDimensions();
    void setValue(int dim, float val);
    float getValue(int dim);

    void add(const Vector *vec);
    void subtract(const Vector *vec);
    void multiply(float scalar);
    void mirrorAxis(int dim);

    void operator=(const Vector &other) const;
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    static Vector add(Vector *vec1, Vector *vec2);
    static Vector subtract(Vector *vec1, Vector *vec2);
    static Vector multiply(Vector *vec1, int scalar);
    static float dotProduct(Vector *vec1, Vector *vec2);

protected:
    static void assertIDInRange(const Vector *vec, int dim);
    static void assertDimensions(const Vector *vec1, const Vector *vec2);

private:
    const int m_dimensions;
    float *m_values;
};

}} // Firestarter::Lib

#endif // __LIB_VECTOR_HPP__

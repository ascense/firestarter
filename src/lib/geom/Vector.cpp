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

#include "lib/geom/Vector.hpp"


namespace Firestarter { namespace Lib {

Vector::Vector(int dim)
         : m_dimensions(dim) {
    m_values = new float[dim];

    for (int i = 0; i < m_dimensions; ++i)
        m_values[i] = 0;
}


Vector::Vector(const Vector *vec)
         : m_dimensions(vec->getDimensions()) {
    m_values = new float[m_dimensions];

    for (int i = 0; i < m_dimensions; ++i)
        m_values[i] = vec->m_values[i];
}


Vector::~Vector() {
    delete[] m_values;
}


int Vector::getDimensions() const {
    return m_dimensions;
}


void Vector::setValue(int dim, float val) {
    assertIDInRange(this, dim);

    m_values[dim - 1] = val;
}


float Vector::getValue(int dim) const {
    assertIDInRange(this, dim);

    return m_values[dim - 1];
}


void Vector::add(const Vector *vec) {
    assertDimensions(this, vec);

    for (int i = 0; i < m_dimensions; ++i)
        m_values[i] += vec->m_values[i];
}


void Vector::subtract(const Vector *vec) {
    assertDimensions(this, vec);

    for (int i = 0; i < m_dimensions; ++i)
        m_values[i] -= vec->m_values[i];
}


void Vector::multiply(float scalar) {
    for (int i = 0; i < m_dimensions; ++i)
        m_values[i] *= scalar;
}


void Vector::operator=(const Vector &rhs) const {
    assertDimensions(this, &rhs);

    if (this != &rhs) {
        for (int i = 0; i < m_dimensions; ++i)
            m_values[i] = rhs.m_values[i];
    }
}


bool Vector::operator==(const Vector &other) const {
    assertDimensions(this, &other);

    for (int i = 0; i < m_dimensions; ++i) {
        if (m_values[i] != other.m_values[i])
            return false;
    }

    return true;
}


bool Vector::operator!=(const Vector &other) const {
    return !(*this == other);
}


// Static Functions

Vector Vector::add(Vector *vec1, Vector *vec2) {
    Vector retVec = new Vector(vec1);
    retVec.add(vec2);

    return retVec;
}


Vector Vector::subtract(Vector *vec1, Vector *vec2) {
    Vector retVec = new Vector(vec1);
    retVec.subtract(vec2);

    return retVec;
}


Vector Vector::multiply(Vector *vec1, int scalar) {
    Vector retVec = new Vector(vec1);
    retVec.multiply(scalar);

    return retVec;
}


float Vector::dotProduct(Vector *vec1, Vector *vec2) {
    assertDimensions(vec1, vec2);

    float ret = 0;
    for (int i = 0; i < vec1->m_dimensions; ++i)
        ret += vec1->m_values[i] * vec2->m_values[i];

    return ret;
}


void Vector::mirrorAxis(int dim) {
    assertIDInRange(this, dim);

    m_values[dim - 1] *= -1;
}


// Protected Static Functions

void Vector::assertIDInRange(const Vector *vec, int dim) {
    if (dim <= 0 || dim > vec->m_dimensions)
        throw FirestarterException("Vector dimension out of range");
}


void Vector::assertDimensions(const Vector *vec1, const Vector *vec2) {
    if (vec1->m_dimensions != vec2->m_dimensions)
        throw FirestarterException("Vectors not of equal dimensions");
}

}} // Firestarter::Lib


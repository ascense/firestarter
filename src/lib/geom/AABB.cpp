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

#include "AABB.hpp"


namespace Firestarter { namespace Lib {

AABB::AABB(int dim)
         : m_dimensions(dim) {
    m_minCoords = new float[dim];
    m_maxCoords = new float[dim];

    for (int i = 0; i < m_dimensions; ++i) {
        m_minCoords[i] = 0;
        m_maxCoords[i] = 0;
    }
}


AABB::AABB(Vector *vec)
         : m_dimensions(vec->getDimensions()) {
    m_minCoords = new float[m_dimensions];
    m_maxCoords = new float[m_dimensions];

    for (int i = 0; i < m_dimensions; ++i) {
        m_minCoords[i] = vec->getValue(i + 1);
        m_maxCoords[i] = vec->getValue(i + 1);
    }
}


AABB::~AABB() {
    delete[] m_minCoords;
    delete[] m_maxCoords;
}


int AABB::getDimensions() {
    return m_dimensions;
}



void AABB::setMinCoords(Vector *vec) {
    assertDimensions(this, vec);

    for (int i = 0; i < m_dimensions; ++i) {
        m_minCoords[i] = vec->getValue(i + 1);
        if (m_maxCoords[i] < m_minCoords[i])
            m_maxCoords[i] = m_minCoords[i];
    }
}


void AABB::setMaxCoords(Vector *vec) {
    assertDimensions(this, vec);

    for (int i = 0; i < m_dimensions; ++i) {
        m_maxCoords[i] = vec->getValue(i + 1);
        if (m_minCoords[i] > m_maxCoords[i])
            m_minCoords[i] = m_maxCoords[i];
    }
}


void AABB::addVector(Vector *vec) {
    assertDimensions(this, vec);

    int tmpVal;
    for (int i = 0; i < m_dimensions; ++i) {
        tmpVal = vec->getValue(i + 1);

        if (tmpVal < m_minCoords[i])
            m_minCoords[i] = tmpVal;
        else if (tmpVal > m_maxCoords[i])
            m_maxCoords[i] = tmpVal;
    }
}


Vector* AABB::p_getMinCoords() {
    Vector *vec = new Vector(m_dimensions);
    for (int i = 0; i < m_dimensions; ++i)
        vec->setValue(i + 1, m_minCoords[i]);

    return vec;
}


Vector* AABB::p_getMaxCoords() {
    Vector *vec = new Vector(m_dimensions);
    for (int i = 0; i < m_dimensions; ++i)
        vec->setValue(i + 1, m_maxCoords[i]);

    return vec;
}


void AABB::assertDimensions(AABB *box, Vector *vec) {
    if (box->getDimensions() != vec->getDimensions())
        throw FirestarterException("AABB and vector not of equal dimensions");
}

}} // Firestarter::Lib


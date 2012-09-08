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

#include "scene/Area.hpp"


namespace Firestarter { namespace Scene {

Area::Area() : data(0), parent(nullptr), children(nullptr) {}


Area::~Area() {
    if (this->children != nullptr) {
        for (int i = 0; i < 4; ++i)
            delete children[i];
        delete [] children;
    }
}


void Area::split() {
    this->children = new Area*[4];
    for (int i = 0; i < 4; ++i) {
        this->children[i] = new Area();
        this->children[i]->parent = this;

        this->children[i]->area_size = this->area_size / 2;
        this->children[i]->area_x = this->area_x;
        this->children[i]->area_z = this->area_z;

        if (i % 2 == 1)
			this->children[i]->area_x += this->children[i]->area_size;
		if (i >= 2)
			this->children[i]->area_z += this->children[i]->area_size;
    }
}


void Area::merge() {
    if (this->children != nullptr)
        return;

    int i;
    for (i = 0; i < 4; ++i) {
        if (this->children[i]->children != nullptr)
            throw Lib::FirestarterException("Merge must be done on the parent of 4 leaf nodes");
    }

    for (i = 0; i < 4; ++i)
        delete children[i];
    delete [] children;

    this->area_size *= 2;
}

}} // Firestarter::Scene

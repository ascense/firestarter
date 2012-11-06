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

#ifndef __SCENE_AREA_HPP_
#define __SCENE_AREA_HPP_

#include "lib/Lib.hpp"

#include "scene/Object.hpp"


namespace Firestarter { namespace Scene {

/* Very basic, non optimal octree implementation */

// FW-Decl.
class Object;


struct Area {
    Area(int size);
    ~Area();

    void split();
    void merge();

    void addObject(Object *obj);
    void removeObject(Object *obj);

    int area_size;
    int area_x;
    int area_y;
    int area_z;

    Object *objects_head;
    Object *objects_tail;
    int objects_count;

    Area *parent;
    Area **children;

private:
    Area();
};

}} // Firestarter::Scene

#endif // __SCENE_AREA_HPP_

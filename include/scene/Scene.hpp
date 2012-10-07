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

#ifndef __SCENE_SCENE_HPP_
#define __SCENE_SCENE_HPP_

#include "Shared.hpp"

#include "Object.hpp"
#include "Area.hpp"


namespace Firestarter { namespace Scene {

/**
* Universal scene object, keeps track of objects and handles scenegraphing
* The data in each scene is independent of others
*/

class Scene {
public:
    Scene();
    ~Scene();

    void addObject(Object *obj);

private:
    Object *p_objs_head;
    Object *p_objs_tail;
    Area *p_octree;
};

}} // Firestarter::Scene

#endif // __SCENE_SCENE_HPP_

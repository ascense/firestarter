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

#include "scene/Scene.hpp"


namespace Firestarter { namespace Scene {

Scene::Scene() {
    p_octree = new Area(128);
}


Scene::~Scene() {
    while (!p_objs.empty()) {
        delete p_objs.back();
        p_objs.pop_back();
    }

    delete p_octree;
}


void Scene::addObject(Object *obj) {
    if (obj == nullptr)
        throw Lib::FirestarterException("Null object added to scene");

    if (obj->p_parent == this)
        return;

    obj->p_id = p_objs.size();
    p_objs.push_back(obj);

    p_octree->addObject(obj);
}


void Scene::removeObject(Object *obj) {
    if (obj->p_id < 0)
        throw Lib::FirestarterException("Requested removal of an object not in scene");

    p_objs[obj->p_id] = p_objs.back();
    p_objs[obj->p_id]->p_id = obj->p_id;
    p_objs.pop_back();

    // this might not be the right place for deletion
    delete obj;
}

}} // Firestarter::Scene

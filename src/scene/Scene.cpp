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

#include "Scene.hpp"


namespace Firestarter { namespace Scene {

Scene::Scene() :
        objects_head(nullptr), objects_tail(nullptr) {}


Scene::~Scene() {
    Object *tmp;
    while (objects_head != nullptr) {
        tmp = objects_head;
        objects_head = objects_head->next();
        delete tmp;
    }
}


void Scene::addObject(Object *obj) {
    if (obj == nullptr) // TODO: Debug exception function, global define for debugs
        throw Lib::FirestarterException("Null object added to scene");

    if (objects_head == nullptr)
        objects_head = obj;
    else
        objects_tail->setNext(obj);

    objects_tail = obj;
}

}} // Firestarter::Scene
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

#include "scene/Object.hpp"

#include "scene/Scene.hpp"


namespace Firestarter { namespace Scene {

Object::Object(Scene *parent) :
        p_area(nullptr), p_id(-1), p_pos(0, 0, 0), p_next_obj(nullptr) {
    parent->addObject(this);
    p_parent = parent;
}


Object::Object(Scene *parent, float x, float y, float z) :
        p_area(nullptr), p_id(-1), p_pos(x, y, z), p_next_obj(nullptr) {
    parent->addObject(this);
    p_parent = parent;
}


Object::~Object() {
    if (p_area != nullptr)
        p_area->removeObject(this);

    for (auto it : p_systems)
        delete [] it;
}


Object* Object::next() {
    return p_next_obj;
}


void Object::setNext(Object *obj) {
    p_next_obj = obj;
}


void Object::attachSystem(uint32_t sysid, uint32_t objid) {
    for (auto it : p_systems) {
        if (it[0] == sysid)
            return;
    }

    uint32_t *idpair = new uint32_t[2];
    idpair[0] = sysid;
    idpair[1] = objid;

    p_systems.push_back(idpair);
}


const Lib::Vec3D* Object::getPosition() const {
    return (const Lib::Vec3D*) &p_pos;
}

}} // Firestarter::Scene

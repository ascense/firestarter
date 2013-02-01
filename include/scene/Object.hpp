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

#ifndef __SCENE_OBJECT_HPP_
#define __SCENE_OBJECT_HPP_

#include <vector>

#include "lib/Lib.hpp"


namespace Firestarter { namespace Scene {

/* Universal Object, Defining the Relationship of a Scene Object */

// FW-Decl.
class Scene;
class Area;


class Object {
friend Scene;
friend Area;

public:
    Object(Scene *parent);
    Object(Scene *parent, float x, float y, float z);
    ~Object();

    Object* next();
    void setNext(Object *obj);

    void attachSystem(uint32_t sysid, uint32_t objid);

    const Lib::Vec3D* getPosition() const;

private:
    Scene *p_parent;
    Area *p_area;

    // systems table, containing uint32_t[2] with systemid, system-specific objectid
    std::vector<uint32_t*> p_systems;

    int p_id;
    Lib::Vec3D p_pos;

    Object *p_next_obj;
};

}} // Firestarter::Scene

#endif // __SCENE_OBJECT_HPP_

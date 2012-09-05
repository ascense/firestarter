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


namespace Firestarter { namespace Scene {

/* Universal Object, Defining the Relationship of a Scene Object */

// FW-Decl. of Scene, to avoid circular referencing
class Scene;


class Object {
public:
    Object(Scene *parent);
    ~Object();

    Object* next();
    void setNext(Object *obj);

private:
    Scene *parent;
    Object *next_obj;
};

}} // Firestarter::Scene

#endif // __SCENE_OBJECT_HPP_

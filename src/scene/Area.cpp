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

#include "scene/Scene.hpp"


namespace Firestarter { namespace Scene {

Area::Area(int size) : area_size(size), objects_head(nullptr), objects_tail(nullptr), objects_count(0), parent(nullptr), children(nullptr) {
    area_x = -area_size / 2;
    area_y = -area_size / 2;
    area_z = -area_size / 2;
}


Area::Area() : objects_head(nullptr), objects_tail(nullptr), objects_count(0), parent(nullptr), children(nullptr) {}


Area::~Area() {
    // delete upwards from leaf nodes
    if (this->children != nullptr) {
        for (int i = 0; i < 8; ++i)
            delete children[i];
        delete [] children;
    }

    // unlink objects
    Object *tmp_obj;
    while (objects_head != nullptr) {
        tmp_obj = objects_head;
        objects_head = objects_head->next();

        tmp_obj->p_area = nullptr;
        tmp_obj->p_parent->removeObject(tmp_obj);
    }
}


void Area::split() {
    this->children = new Area*[8];
    for (int i = 0; i < 8; ++i) {
        this->children[i] = new Area();
        this->children[i]->parent = this;

        this->children[i]->area_size = this->area_size / 2;
        this->children[i]->area_x = this->area_x;
        this->children[i]->area_y = this->area_y;
        this->children[i]->area_z = this->area_z;

        if (i % 2 == 1)
			this->children[i]->area_x += this->children[i]->area_size;
		if (i % 4 >= 2)
			this->children[i]->area_z += this->children[i]->area_size;
		if (i >= 4)
			this->children[i]->area_y += this->children[i]->area_size;
    }

    Object *tmp_obj = objects_head;
    while (objects_head != nullptr) {
        tmp_obj = objects_head;
        objects_head = tmp_obj->next();

        addToChild(tmp_obj);
    }

    objects_count = 0;
    objects_head = objects_tail = nullptr;
}


void Area::merge() {
    if (this->children != nullptr)
        return;

    int i;

    int new_obj_count = objects_count;
    for (i = 0; i < 8; ++i) {
        if (this->children[i]->children != nullptr)
            throw Lib::FirestarterException("Merge failed, all child nodes of the merge point must be leaf nodes");

        new_obj_count += children[i]->objects_count;
    }

    if (new_obj_count > 8)
        throw Lib::FirestarterException("Merge failed, too many objects in child nodes");

    this->area_size *= 2;

    for (i = 0; i < 8; ++i) {
        if (objects_tail != nullptr) {
            objects_tail->setNext(children[i]->objects_head);
            objects_count += children[i]->objects_count;
        } else {
            objects_head = children[i]->objects_head;
            objects_tail = children[i]->objects_tail;
            objects_count = children[i]->objects_count;
        }

        delete children[i];
    }

    delete [] children;
}


void Area::addObject(Object *obj) {
    if (children != nullptr) {
        addToChild(obj);
        return;
    }

    if (objects_tail != nullptr)
        objects_tail->setNext(obj);
    else
        objects_head = obj;
    objects_tail = obj;

    obj->p_area = this;
    obj->setNext(nullptr);

    if (++objects_count > P_SPLIT_AT)
        split();
}


void Area::removeObject(Object *obj) {
    Object* tmp_obj = objects_head;

    if (objects_head == nullptr)
        return;

    if (obj == objects_head) {
        objects_head = objects_head->next();
        tmp_obj = nullptr;
    } else {
        while (tmp_obj->next() != obj) {
            if (tmp_obj->next() == nullptr)
                return;

            tmp_obj = tmp_obj->next();
        }
    }

    if (obj == objects_tail)
        objects_tail = tmp_obj;
    else if (tmp_obj != nullptr)
        tmp_obj->setNext(obj->next());

    obj->p_area = nullptr;
    obj->setNext(nullptr);

    if (--objects_count <= P_MERGE_AT)
        merge();
}


void Area::addToChild(Object *obj) {
    int id = 0;

    if (obj->p_pos.getX() >= area_x + (area_size / 2))
        id += 1;
    if (obj->p_pos.getZ() >= area_z + (area_size / 2))
        id += 2;
    if (obj->p_pos.getY() >= area_y + (area_size / 2))
        id += 4;

    this->children[id]->addObject(obj);
}

}} // Firestarter::Scene

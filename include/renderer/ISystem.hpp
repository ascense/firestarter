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

#ifndef __RENDERER_ISYSTEM_HPP_
#define __RENDERER_ISYSTEM_HPP_

#include "systems/AbstractISystem.hpp"
#include "systems/DataUpdate.hpp"


namespace Firestarter { namespace Renderer {

class System;

/* External Interface for rendering subsystem */

class ISystem : public Systems::AbstractISystem {
public:
    ISystem(System *sys);
    ~ISystem();

    //  Process one tick (delta seconds) of the game world
    void tick(double delta, const Scene::Scene* scene);
    //  Recieve notification of data changes relevant to this subsystem
    void notify(Systems::DataUpdate* upd);

    const std::string* getSystemName();
};

}} // Firestarter::Renderer

#endif // __RENDERER_ISYSTEM_HPP_

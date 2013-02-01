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

#ifndef __SCRIPT_SYSTEM_HPP_
#define __SCRIPT_SYSTEM_HPP_

#include <string>

#include "systems/AbstractSystem.hpp"

#include "ISystem.hpp"


namespace Firestarter { namespace Script {

/* Scripting subsystem */

class System : public Systems::AbstractSystem {
friend class ISystem;

public:
    System();
    ~System();

    void init();

    void tick(double delta, const Scene::Scene* scene);
    void notify(Systems::DataUpdate* upd);

    const ISystem* getInterface();

private:
    ISystem *p_iface;
};

}} // Firestarter::Script

#endif // __SCRIPT_SYSTEM_HPP_

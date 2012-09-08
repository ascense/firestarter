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

#ifndef __SYSTEMS_ABSTRACTSYSTEM_HPP_
#define __SYSTEMS_ABSTRACTSYSTEM_HPP_

#include <string>

#include "scene/Scene.hpp"

#include "AbstractISystem.hpp"
#include "DataUpdate.hpp"


namespace Firestarter { namespace Systems {

class AbstractISystem;


/* Abstract System, Defining the Generic Framework of a Game System */

class AbstractSystem {
friend class AbstractISystem;

public:
    AbstractSystem(std::string* name);
    virtual ~AbstractSystem();

    //  All systems are guaranteed to be instantized,
    //+ but not neccessarily initialized during System.init()
    virtual void init() = 0;

    virtual void tick(double delta, const Scene::Scene* scene) = 0;
    virtual void notify(DataUpdate* upd) = 0;

    virtual const AbstractISystem* getInterface() = 0;

    const std::string* getName();

protected:
    const std::string* p_name;
};

}} // Firestarter::Core


#endif // __SYSTEMS_ABSTRACTSYSTEM_HPP_

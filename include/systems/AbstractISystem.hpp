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

#ifndef __SYSTEMS_ABSTRACTISYSTEM_HPP_
#define __SYSTEMS_ABSTRACTISYSTEM_HPP_

#include <string>

#include "AbstractSystem.hpp"
#include "DataUpdate.hpp"


namespace Firestarter { namespace Systems {

// FW-Decl
class AbstractSystem;


/* Abstract System Interface, Defining the Framework Used to Provide Services to Other Systems */

class AbstractISystem {
public:
    AbstractISystem(AbstractSystem *sys);
    virtual ~AbstractISystem();

    //  Process one tick (delta seconds) of the game world
    virtual void tick(double delta, const Scene::Scene* scene) = 0;
    //  Recieve notification of data changes relevant to this subsystem
    virtual void notify(DataUpdate* upd) = 0;

    const std::string* getSystemName();

protected:
    AbstractSystem *getSystem();

private:
    AbstractSystem *const p_system;
};

}} // Firestarter::Core

#endif // __SYSTEMS_ABSTRACTISYSTEM_HPP_


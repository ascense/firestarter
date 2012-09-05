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

#ifndef __MANAGERS_SERVICEMGR_HPP_
#define __MANAGERS_SERVICEMGR_HPP_

#include <string>
#include <vector>

#include "../lib/Lib.hpp"
#include "../systems/AbstractSystem.hpp"
#include "../systems/AbstractISystem.hpp"


namespace Firestarter { namespace Core {
    class Engine; // Forward Declaration of Friend Class
}}


namespace Firestarter { namespace Managers {

/* Manager for Systems and Services */

class ServiceMgr {
friend class Core::Engine;

public:
    Systems::AbstractISystem* getSystemInterface(const std::string *name);

protected:
    ServiceMgr();
    ~ServiceMgr();

    void init();

    void registerSystem(Systems::AbstractSystem *sys);

    int getSystemID(const std::string *name); // use lookup

private:
    std::vector<Systems::AbstractSystem*> p_systems;
    // TODO: Lookup-table(sys_name) -> sys_id
};

}} // Firestarter::Managers

#endif // __MANAGERS_SERVICEMGR_HPP_

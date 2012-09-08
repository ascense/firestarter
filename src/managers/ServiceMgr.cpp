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

#include "managers/ServiceMgr.hpp"


namespace Firestarter { namespace Managers {

ServiceMgr::ServiceMgr() {}


ServiceMgr::~ServiceMgr() {
    std::vector<Systems::AbstractSystem*>::iterator it;
    for (it = p_systems.begin(); it < p_systems.end(); it++)
        delete *it;
}


void ServiceMgr::init() {
    std::vector<Systems::AbstractSystem*>::iterator it;
    for (it = p_systems.begin(); it < p_systems.end(); it++)
        (*it)->init();
}


void ServiceMgr::registerSystem(Systems::AbstractSystem *sys) {
    p_systems.push_back(sys);

    // TODO: add to lookup
}

}} // Firestarter::Managers

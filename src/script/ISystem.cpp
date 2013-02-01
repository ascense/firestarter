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

#include "script/ISystem.hpp"

#include "script/System.hpp"


namespace Firestarter { namespace Script {

ISystem::ISystem(System *sys) :
        Systems::AbstractISystem(sys) {}


ISystem::~ISystem() {}


void ISystem::tick(double delta, const Scene::Scene* scene) {
    this->getSystem()->tick(delta, scene);
}


void ISystem::notify(Systems::DataUpdate* upd) {
    this->getSystem()->notify(upd);
}

}} // Firestarter::Script
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

#include "renderer/System.hpp"


namespace Firestarter { namespace Renderer {

System::System()
         : Systems::AbstractSystem(new std::string("renderer")), p_screen(nullptr) {
    p_iface = new ISystem(this);
}


System::~System() {
    delete p_iface;

    if (p_screen != nullptr)
        delete p_screen;
}


void System::init() {
    if (p_screen != nullptr)
        return;

    p_screen = new Screen(800, 600, false);
}


void System::tick(double delta, const Scene::Scene* scene) {
    p_screen->draw();
}


void System::notify(Systems::DataUpdate* upd) {}


const ISystem* System::getInterface() {
    return p_iface;
}

}} // Firestarter::Renderer

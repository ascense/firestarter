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

#include "Engine.hpp"


namespace Firestarter { namespace Core {

Engine::Engine() {
    mgr_task = new Managers::TaskMgr();
    mgr_state = new Managers::StateMgr();
    mgr_srv = new Managers::ServiceMgr();
    mgr_env = new Managers::EnvironmentMgr();
    mgr_pf = new Managers:: PlatformMgr();
}


Engine::~Engine() {
    delete mgr_task;
    delete mgr_state;
    delete mgr_srv;
    delete mgr_env;
    delete mgr_pf;
}


void Engine::run() {
    init();
    main();
}


void Engine::init() {
    mgr_srv->registerSystem(new Renderer::System());

    mgr_srv->init();
}


void Engine::main() {
    while (mgr_state->getRunning()) {
        processInput();
        processTasks();

        distribute();

        // check task results

        // TMP EXIT
        mgr_state->stop();
    }
}


void Engine::processInput() {}


void Engine::processTasks() {}


void Engine::distribute() {}

}} // Firestarter::Core

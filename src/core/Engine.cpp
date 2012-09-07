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

Engine::Engine() {}


Engine::~Engine() {}


void Engine::run() {
    init();
    main();
}


void Engine::init() {
    mgr_srv.registerSystem(new Renderer::System());

    mgr_srv.init();
}


void Engine::main() {
    while (true) {
        processInput();
        if (!mgr_state.getRunning())
            break;

        processTasks();

        distribute();

        // check task results
    }
}


void Engine::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_MOUSEMOTION:
                mgr_input.updateMouse(&event.motion);
                break;

            case SDL_KEYDOWN:
                mgr_input.setKeyDown(&event.key.keysym.sym);
                break;

            case SDL_KEYUP:
                mgr_input.setKeyUp(&event.key.keysym.sym);
                break;

            case SDL_QUIT:
                mgr_state.stop();
                return;

            default:
                break;
        }
    }
}


void Engine::processTasks() {}


void Engine::distribute() {}

}} // Firestarter::Core

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

#ifndef __CORE_ENGINE_HPP_
#define __CORE_ENGINE_HPP_

#include "managers/Managers.hpp"
#include "renderer/System.hpp"


namespace Firestarter { namespace Core {

/* Engine Framework and Main Loop */

class Engine {
public:
    Engine();
    ~Engine();

    void run();

    /* Singleton-like handling of manager access
    *  These are only for public access to the managers,
    *+ the Engine-class owns all the actual instances.
    *  Ugly, but functional...
    */
    static Managers::EnvironmentMgr *const getEnvironmentMgr();
    static Managers::InputMgr *const getInputMgr();
    static Managers::PlatformMgr *const getPlatformMgr();
    static Managers::ServiceMgr *const getServiceMgr();
    static Managers::StateMgr *const getStateMgr();
    static Managers::TaskMgr *const getTaskMgr();

private:
    void init();
    void main();

    void processInput();
    void processTasks();
    void distribute();

    // Managers:
    Managers::EnvironmentMgr mgr_env;
    Managers::InputMgr mgr_input;
    Managers::PlatformMgr mgr_pf;
    Managers::ServiceMgr mgr_srv;
    Managers::StateMgr mgr_state;
    Managers::TaskMgr mgr_task;

    Scene::Scene p_scene;

    static Engine* p_instance;
};

}} // Firestarter::Core

#endif // __CORE_ENGINE_HPP_

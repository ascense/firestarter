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

#ifndef __MANAGERS_TASKMGR_HPP_
#define __MANAGERS_TASKMGR_HPP_

#include <boost/thread/mutex.hpp>

#include "Shared.hpp"
#include "systems/AbstractSystem.hpp"

#include "Task.hpp"
#include "Worker.hpp"


namespace Firestarter { namespace Core {
    class Engine; // Forward Declaration of Friend Class
}}


namespace Firestarter { namespace Managers {

/* Manager for Adding, Scheduling and Checking System Tasks */

class TaskMgr {
friend class Core::Engine;

public:
    void addTask(Task *task);

protected:
    TaskMgr();
    ~TaskMgr();

    void init();

    void checkTask();

    void schedule();
    void run();

private:
    boost::mutex *p_lock;

    Task *p_taskQueue;
    Task *p_taskQueueTail;
    Task *p_taskSchedule;
    Task *p_taskResults;

    Worker *p_threadPool;
    int p_threadCount;
};

}} // Firestarter::Managers

#endif // __MANAGERS_TASKMGR_HPP_

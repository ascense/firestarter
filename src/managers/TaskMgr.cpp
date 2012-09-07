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

#include "TaskMgr.hpp"


namespace Firestarter { namespace Managers {

// CLASS: Task //

Task::Task(Systems::AbstractSystem *sys, Scene::Scene *scene)
         : system(sys), scene(scene), next(nullptr) {}


Task::~Task() {}


// CLASS: TaskMgr //

TaskMgr::TaskMgr() :
        p_taskQueue(nullptr), p_taskQueueTail(nullptr), p_taskSchedule(nullptr), p_taskResults(nullptr) {}


TaskMgr::~TaskMgr() {
    Task *task;
    while (p_taskQueue != nullptr) {
        task = p_taskQueue;
        p_taskQueue = task->next;

        delete task;
    }
}


void TaskMgr::addTask(Task *task) {
    if (p_taskQueue == nullptr) {
        p_taskQueue = task;
        p_taskQueueTail = task;
    } else {
        p_taskQueueTail->next = task;
        p_taskQueueTail = task;
    }
}


void TaskMgr::run() {
    // Assign tasks to the threads in the thread pool
    // Due to the limitations of SDL, rendering has to (always) be done in this thread
}

}} // Firestarter::Managers

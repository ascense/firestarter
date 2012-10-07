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

#include "managers/TaskMgr.hpp"

#include "Firestarter.hpp"


namespace Firestarter { namespace Managers {

TaskMgr::TaskMgr() :
        p_taskQueue(nullptr), p_taskQueueTail(nullptr), p_taskSchedule(nullptr), p_taskResults(nullptr), p_threadPool(nullptr) {
    p_lock = new boost::mutex();
}


TaskMgr::~TaskMgr() {
    delete p_taskQueue;
    delete p_taskSchedule;

    delete [] p_threadPool;

    delete p_lock;
}


void TaskMgr::init() {
    p_threadCount = Core::Engine::getPlatformMgr()->getCPUCores() - 1;
    if (p_threadCount < 2)
        p_threadCount = 2;

    p_threadPool = new Worker[p_threadCount];
    for (int i = 0; i < p_threadCount; ++i)
        p_threadPool[i].start();
}


void TaskMgr::addTask(Task *task) {
    p_lock->lock();
    if (p_taskQueue == nullptr) {
        p_taskQueue = task;
        p_taskQueueTail = task;
    } else {
        p_taskQueueTail->next = task;
        p_taskQueueTail = task;
    }
    p_lock->unlock();
}


void TaskMgr::schedule() {
    // Assign tasks to the threads in the thread pool

    Task *nextTask = p_taskQueue;
    int i = 0;

    while (nextTask != nullptr) {
        p_lock->lock();
        p_taskQueue = nextTask;
        nextTask = p_taskQueue->next;
        p_lock->unlock();

        // Due to the limitations of SDL, rendering has to (always) be done in this thread
        if (strcmp(p_taskQueue->system->getName()->c_str(), "renderer") != 0) {
            p_threadPool[i % p_threadCount].addTask(p_taskQueue);
            ++i;
        } else {
            p_taskQueue->next = p_taskSchedule;
            p_taskSchedule = p_taskQueue;
        }
    }

    p_lock->lock();
    p_taskQueue = nullptr;
    p_lock->unlock();
}


void TaskMgr::run() {
    // Wake up the worker-threads, in order to process a new frame
    for (int i = 0; i < p_threadCount; ++i)
        p_threadPool[i].notify();

    Task *tmpTask;

    // Run tasks reserved for this thread
    while (p_taskSchedule != nullptr) {
        p_taskSchedule->system->tick(0, p_taskSchedule->scene);

        p_lock->lock();
        tmpTask = p_taskResults;
        p_taskResults = p_taskSchedule;
        p_taskSchedule = p_taskSchedule->next;
        p_taskResults->next = tmpTask;
        p_lock->unlock();
    }

    delete p_taskResults;
    p_taskResults = nullptr;
}

}} // Firestarter::Managers

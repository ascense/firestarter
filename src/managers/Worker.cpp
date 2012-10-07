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

#include "managers/Worker.hpp"


namespace Firestarter { namespace Managers {

Worker::Worker()
        : p_thread(nullptr), p_running(false), p_taskSchedule(nullptr), p_taskResults(nullptr) {}


Worker::~Worker() {
    stop();

    if (p_taskSchedule != nullptr)
        delete p_taskSchedule;

    if (p_taskResults != nullptr)
        delete p_taskResults;

    delete p_thread;
}


void Worker::start() {
    if (p_thread == nullptr) {
        p_running = true;
        p_thread = new boost::thread(&Worker::run, this);
    }
}


void Worker::addTask(Task *task) {
    boost::unique_lock<boost::mutex> lock(p_lock);

    task->next = p_taskSchedule;
    p_taskSchedule = task;
}


void Worker::checkTask() {}


void Worker::notify() {
    p_cond.notify_all();
}


void Worker::stop() {
    p_lock.lock();
    p_running = false;
    p_taskSchedule = nullptr;
    p_lock.unlock();

    p_cond.notify_all();

    // this might hang, so might not be ok for the destructor...
    if (p_thread != nullptr && p_thread->joinable())
        p_thread->join();
}


void Worker::run() {
    Task *currTask;

    boost::unique_lock<boost::mutex> lock(p_lock);

    while (p_running) {
        // While tasks in queue
        while (p_taskSchedule != nullptr) {
            // Grab task
            currTask = p_taskSchedule;
            p_taskSchedule = p_taskSchedule->next;

            // Run task
            p_lock.unlock();
            currTask->system->tick(0, currTask->scene);
            p_lock.lock();

            // Store results
            currTask->next = p_taskResults;
            p_taskResults = currTask;
        }

        p_cond.wait(p_lock);
    }
}

}} // Firestarter::Managers

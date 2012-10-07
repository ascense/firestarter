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

#ifndef __MANAGERS_WORKER_HPP_
#define __MANAGERS_WORKER_HPP_

#define BOOST_THREAD_USE_LIB
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

#include "Shared.hpp"
#include "systems/AbstractSystem.hpp"

#include "Task.hpp"


namespace Firestarter { namespace Managers {

/* Class for handling of worker threads for task execution */

class Worker : private boost::noncopyable {
public:
    Worker();
    ~Worker();

    void start();
    void stop();

    void run();

    void addTask(Task *task);
    void checkTask();

    void notify();

private:
    boost::mutex p_lock;
    boost::condition p_cond;

    boost::thread *p_thread;

    bool p_running;

    Task *p_taskSchedule;
    Task *p_taskResults;
};

}} // Firestarter::Managers

#endif // __MANAGERS_TASKMGR_HPP_

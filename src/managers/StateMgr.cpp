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

#include "managers/StateMgr.hpp"

#include "Firestarter.hpp"


namespace Firestarter { namespace Managers {

StateMgr::StateMgr() :
        running(true) {
    p_lock = new boost::mutex();
}


StateMgr::~StateMgr() {
    delete p_lock;
}


bool StateMgr::getRunning() {
    return running;
}


void StateMgr::stop() {
    p_lock->lock();
    running = false;
    p_lock->unlock();
}

}} // Firestarter::Managers

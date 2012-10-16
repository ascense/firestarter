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

#include "managers/PlatformMgr.hpp"

#include "Firestarter.hpp"


namespace Firestarter { namespace Managers {

PlatformMgr::PlatformMgr() : p_cpuCores(-1) {
    p_lock = new boost::mutex();
}


PlatformMgr::~PlatformMgr() {
    delete p_lock;
}


int PlatformMgr::getCPUCores() {
    if (p_cpuCores < 0) {
        p_lock->lock();
        p_cpuCores = pf_getCPUCores();
        p_lock->unlock();
    }

    return p_cpuCores;
}


uint64_t PlatformMgr::getCurrentTime() {
    return pf_getCurrentTime();
}


inline uint64_t PlatformMgr::getCPUTicks() {
    uint32_t lo, hi;

    // use RDTSC for tick count
    __asm__ __volatile__(
        "xorl %%eax, %%eax\n"
        "cpuid\n"
        "rdtsc\n"
        : "=a" (lo), "=d" (hi)
        :
        : "%ebx", "%ecx"
    );

    return (uint64_t) hi << 32 | lo;
}

}} // Firestarter::Managers

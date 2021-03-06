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

#include <windows.h>
#include <stdio.h>


namespace Firestarter { namespace Managers {

int PlatformMgr::pf_getCPUCores() {
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);

    return sysinfo.dwNumberOfProcessors;
}


// Note: on some chipsets, QPC may do occasional erroneus leaps of several seconds
uint64_t PlatformMgr::pf_getCurrentTime() {
    LARGE_INTEGER li_freq, li_time;

    QueryPerformanceFrequency(&li_freq);
    QueryPerformanceCounter(&li_time);

    return (uint64_t) li_time.QuadPart / ((uint64_t) li_freq.QuadPart / 1000LL);
}

}} // Firestarter::Managers

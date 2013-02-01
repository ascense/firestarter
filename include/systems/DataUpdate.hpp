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

#ifndef __SYSTEMS_DATAUPDATE_HPP_
#define __SYSTEMS_DATAUPDATE_HPP_

#include "lib/Lib.hpp"


namespace Firestarter { namespace Systems {

/* Object Update Data, Used for Notifying Systems of a Change to an Object */

enum updateType {
    TYPE_CUMULATIVE_ORDERED, // Apply updates cumulatively, in temporal order
    TYPE_CUMULATIVE_RANDOM,  // Apply updates cumulatively, in any order (allows for faster processing)
    TYPE_DIRECT              // Use the value of the newest update as is, ignore older
};

enum updateContent {
    CONTENT_POSITION, // Update concerns positional data

};

struct DataUpdate {
    DataUpdate(updateType type, updateContent content);
    ~DataUpdate();

    const updateType type;
    const updateContent content;

    uint64_t time;

    // TODO: actual update data
};

}} // Firestarter::Systems


#endif // __SYSTEMS_DATAUPDATE_HPP_



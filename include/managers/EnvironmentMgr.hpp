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

#ifndef __MANAGERS_ENVIRONMENTMGR_HPP_
#define __MANAGERS_ENVIRONMENTMGR_HPP_

#include "Precompile.hpp"


namespace Firestarter { namespace Managers {

/* Manager for Engine Variables */

class EnvironmentMgr {
friend class Core::Engine;

protected:
    EnvironmentMgr();
    ~EnvironmentMgr();

    void addVariable();
    void delVariable();

    void setValue();
    void getValue();
};

}} // Firestarter::Managers

#endif // __MANAGERS_ENVIRONMENTMGR_HPP_

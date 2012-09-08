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

#ifndef __LIB_EXCEPTION_HPP_
#define __LIB_EXCEPTION_HPP_

#include <exception>


namespace Firestarter { namespace Lib {

/* Engine Exceptions */

class FirestarterException : public std::exception {
public:
    FirestarterException(const char* msg);

    const char* what();

private:
    const char* msg;
};


class CriticalError : public FirestarterException {
public:
    CriticalError(const char* msg) : FirestarterException(msg) {};
};

}} // Firestarter::Lib

#endif // __LIB_EXCEPTION_HPP_

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

#include <iostream>

#include "Firestarter.hpp"


int main(int argc, char *argv[]) {
    Firestarter::Core::Engine *engine = nullptr;
    int ecode = 0;

    try {
        engine = new Firestarter::Core::Engine();
        engine->run();
    } catch (Firestarter::Lib::CriticalError& e) {
        std::cout << "Critical Error!" << std::endl;
        std::cout << e.what() << std::endl;
        ecode = 7;
    } catch (Firestarter::Lib::FirestarterException& e) {
        std::cout << "Internal Error!" << std::endl;
        std::cout << e.what() << std::endl;
        ecode = 5;
    }

    if (engine)
        delete engine;

    return ecode;
}

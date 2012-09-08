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

#ifndef __MANAGERS_INPUTMGR_HPP_
#define __MANAGERS_INPUTMGR_HPP_

#include <SDL/SDL.h>

#include "Precompile.hpp"
#include "lib/Lib.hpp"


namespace Firestarter { namespace Managers {

/* Manager for Engine Variables */

class InputMgr {
friend class Core::Engine;

protected:
    InputMgr();
    ~InputMgr();

    // Keyboard
    void setKeyDown(const SDLKey *key);
    void setKeyUp(const SDLKey *key);

    bool isKeyDown(const SDLKey *key);

    void clearKeys();

    // Mouse
    void updateMouse(const SDL_MouseMotionEvent *event);

    void setMouseSensitivity(float sens);
    void setMouseYawFactor(float m_yaw);
    void setMousePitchFactor(float m_pitch);

    Lib::Vec2D* getMousePosition();
    Lib::Vec2D* getMouseMovement();

private:
    void assertKeyInRange(const SDLKey *key);

    void updateMouseScaling();

    bool p_keyDown[SDLK_LAST];
    Lib::Vec2D p_mousePos; // Mouse coords from last update
    Lib::Vec2D p_mouseRel; // Relative mouse motion from last update

    // Mouse sensitivity multipliers
    float p_mouseFactor;
    float p_mouseYaw;
    float p_mousePitch;
    Lib::Vec2D p_mouseScaling;
};

}} // Firestarter::Managers

#endif // __MANAGERS_INPUTMGR_HPP_

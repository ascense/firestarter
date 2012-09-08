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

#include "managers/InputMgr.hpp"


namespace Firestarter { namespace Managers {

InputMgr::InputMgr()
         : p_mouseFactor(10), p_mouseYaw(0.22f), p_mousePitch(0.22f) {
    clearKeys();
    updateMouseScaling();
}


InputMgr::~InputMgr() {}


void InputMgr::setKeyDown(const SDLKey *key) {
    assertKeyInRange(key);

    p_keyDown[*key] = true;
}


void InputMgr::setKeyUp(const SDLKey *key) {
    assertKeyInRange(key);

    p_keyDown[*key] = false;
}


bool InputMgr::isKeyDown(const SDLKey *key) {
    assertKeyInRange(key);

    return p_keyDown[*key];
}


void InputMgr::clearKeys() {
    for (int i = 0; i < SDLK_LAST; ++i)
        p_keyDown[i] = false;
}


void InputMgr::updateMouse(const SDL_MouseMotionEvent *event) {
    p_mousePos.setX(event->x);
    p_mousePos.setY(event->y);

    p_mouseRel.setX(event->xrel * p_mouseScaling.getX());
    p_mouseRel.setY(event->yrel * p_mouseScaling.getY());
}


void InputMgr::setMouseSensitivity(float sens) {
    p_mouseFactor = sens;

    updateMouseScaling();
}


void InputMgr::setMouseYawFactor(float m_yaw) {
    p_mouseYaw = m_yaw;

    updateMouseScaling();
}


void InputMgr::setMousePitchFactor(float m_pitch) {
    p_mousePitch = m_pitch;

    updateMouseScaling();
}


Lib::Vec2D* InputMgr::getMousePosition() {
    return &p_mousePos;
}


Lib::Vec2D* InputMgr::getMouseMovement() {
    return &p_mouseRel;
}


void InputMgr::assertKeyInRange(const SDLKey *key) {
    if (*key >= SDLK_LAST)
        throw Lib::FirestarterException("Key ID out of range");
}


void InputMgr::updateMouseScaling() {
    p_mouseScaling.setX(p_mouseYaw);
    p_mouseScaling.setY(p_mousePitch);
    p_mouseScaling.multiply(p_mouseFactor);
}

}} // Firestarter::Managers

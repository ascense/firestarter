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

#ifndef __RENDERER_SCREEN_HPP_
#define __RENDERER_SCREEN_HPP_

#include <cmath>
#include <GL/glew.h>
#include <SDL/SDL.h>

#include "lib/Lib.hpp"


namespace Firestarter { namespace Renderer {

class Screen {
public:
    Screen(int width, int height, bool fullscreen) throw (Lib::FirestarterException);
    ~Screen();

    void draw();

    bool setVideoMode(int width, int height, int bpp, bool fullscreen);

    void setMouseGrab(bool grabbed);
    void setVSync(bool vsync);
    void setFov(int fov);

protected:
    void setGLBuffer(int col_bits, int depth_bits);
    void setProjection(int fov, double near, double far);
    void setShading();

    void checkGLErr();

private:
    SDL_Surface *p_surface;

    int p_width, p_height;
    bool p_fullscreen;

    double p_znear, p_zfar;
};

}} // Firestarter::Renderer

#endif // __RENDERER_SCREEN_HPP_

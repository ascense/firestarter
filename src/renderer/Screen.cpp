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

#include "renderer/Screen.hpp"


namespace Firestarter { namespace Renderer {

Screen::Screen(int width, int height, bool fullscreen) throw (Lib::FirestarterException) {
    p_znear = 0.1;
    p_zfar = 500;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Lib::CriticalError("Failed to initialize SDL video subsystem");

    if (!setVideoMode(width, height, -1, fullscreen)) {
        SDL_Quit();
        throw Lib::CriticalError("Failed to set video mode for new window");
    }

    if (GLEW_OK != glewInit()) {
        SDL_Quit();
        throw Lib::CriticalError("Failed to initialize OpenGL extension wrangler");
    }

    SDL_WM_SetCaption("Firestarter Engine Demo", "Firestarter");
    setShading();
}


Screen::~Screen() {
    SDL_Quit();
}


void Screen::draw(const Scene::Scene* scene) {
    Lib::Vec3D *cam_pos;

    // 0'th object in scene considered the camera
    if (scene->getObject(0) == nullptr) {
        cam_pos = new Lib::Vec3D(0, 0, 0);
    } else {
        cam_pos = new Lib::Vec3D(scene->getObject(0)->getPosition());
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    /**
    glRotatef(cam_rot->getX(), 1.0f, 0.0f, 0.0f);
    glRotatef(cam_rot->getY(), 0.0f, 1.0f, 0.0f);
    glRotatef(cam_rot->getZ(), 0.0f, 0.0f, 1.0f);
    **/

    // draw_sky();

    glTranslatef(-cam_pos->getX(), -cam_pos->getX() - 0.9, -cam_pos->getX());

    // draw_world();

    glLoadIdentity();

    glClear(GL_DEPTH_BUFFER_BIT);

    // draw_ui();

    SDL_GL_SwapBuffers();

    delete cam_pos;
}


// Change the screen geometry and fullscreen mode
bool Screen::setVideoMode(int width, int height, int bpp, bool fullscreen) {
    int flags = SDL_OPENGL;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;

    // query SDL for the current BPP value, if no specific BPP was requested
    if (bpp < 0) {
        const SDL_VideoInfo *info = SDL_GetVideoInfo();
        if (!info)
            bpp = 24;
        else
            bpp = info->vfmt->BitsPerPixel;
    }

    // attempt to request buffers of 8 bits per color, 16 for depth
    setGLBuffer(8, 16);
    p_surface = SDL_SetVideoMode(width, height, bpp, flags);

    // some systems only allow for 6 bits per color, so try that instead
    if (!p_surface) {
        setGLBuffer(6, 16);
        p_surface = SDL_SetVideoMode(width, height, bpp, flags);
    }

    // failed to find an acceptable video mode
    if (!p_surface)
        return false;

    this->p_width = width;
    this->p_height = height;
    this->p_fullscreen = fullscreen;

    // for now, exit incase doublebuffering was not supported
    int dbuf;
    if (SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER, &dbuf) < 0 || dbuf != 1)
        return false;

    setProjection(90, p_znear, p_zfar);

    setMouseGrab(fullscreen);

    return true;
}


// Set OpenGL buffer sizes requested by SDL
void Screen::setGLBuffer(int col_bits, int depth_bits) {
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, col_bits);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, col_bits);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, col_bits);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, depth_bits);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}


// Recalculate the view frustum settings for projection matrix
void Screen::setProjection(int fov, double near, double far) {
    if (p_znear != near)
        p_znear = near;
    if (p_zfar != far)
        p_zfar = far;

    GLdouble aspect = (double) (p_height) / (double) (p_width);
    GLdouble top = std::tan(fov * M_PI / 360.0) * near * aspect;
    GLdouble right = std::tan(fov * M_PI / 360.0) * near;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-right, right, -top, top, near, far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Set the default shading options
void Screen::setShading() {
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    if (GLEW_VERSION_1_4)
        glHint(GL_GENERATE_MIPMAP_HINT, GL_NICEST);

    glShadeModel(GL_SMOOTH);
    glClearColor(0, 0, 0, 0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}


void Screen::setFov(int fov) {
    setProjection(fov, p_znear, p_zfar);
}


void Screen::setMouseGrab(bool grabbed) {
    if (grabbed) {
        SDL_ShowCursor(0);
        SDL_WM_GrabInput(SDL_GRAB_ON);
    } else {
        SDL_ShowCursor(1);
        SDL_WM_GrabInput(SDL_GRAB_OFF);
    }
}


void Screen::setVSync(bool vsync) {
    SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, (vsync == true));
}


void Screen::checkGLErr() {
    GLenum err;
    if ((err = glGetError()) != GL_NO_ERROR)
        throw Lib::CriticalError("OpenGL Error, code " + err);
}

}} // Firestarter::Renderer

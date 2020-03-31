#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL.h>
#include <SDL_opengl.h>

namespace sdl {

    class Window {
    public:
        enum class Status {
            Good,
            InitFailed,
        };

        Window();
        ~Window();

        void swapWindow() const;
    private:
        Status init();

        SDL_Window* m_mainWindow;
        SDL_GLContext m_mainContext;
    };

}

#endif

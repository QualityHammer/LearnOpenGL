#pragma once
#ifndef SDL_ERRORS_HPP
#define SDL_ERRORS_HPP
#include <SDL.h>
#include <iostream>
#include <array>
#include <string>

namespace sdl {

    enum class SDLErrorMsg : unsigned int {
        INIT_ERROR,             // 0
        WINDOW_INIT_ERROR,      // 1
        CONTEXT_INIT_ERROR,     // 2
        VSYNC_INIT_ERROR,       // 3
        MSG_COUNT               // # of error messages
    };

    class SDLErrorHandler {
    public:
        static void SDLError(const SDLErrorMsg msg);
    private:
        static const std::array<std::string, 
            static_cast<unsigned int>(SDLErrorMsg::MSG_COUNT)>
            m_errorMsgStrings;
    };

}

#endif

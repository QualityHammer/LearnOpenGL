#include "client/sdl/SDLErrors.hpp"

namespace sdl {

    const std::array<std::string, 
            static_cast<unsigned int>(SDLErrorMsg::MSG_COUNT)>
            SDLErrorHandler::m_errorMsgStrings{{
                "SDL could not initialize!",
                "Window could not be created!",
                "OpenGL context could not be created!",
                "Warning: Unable to set VSync.",
            }};

    void SDLErrorHandler::SDLError(const SDLErrorMsg msg) {
        std::cout << m_errorMsgStrings[static_cast<unsigned int>(msg)]
                  << " SDL Error: " << std::endl
                  << SDL_GetError() << std::endl;
    }

}

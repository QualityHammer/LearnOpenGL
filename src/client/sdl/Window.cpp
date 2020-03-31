#include <iostream>
#include <glad/glad.h>

#include "client/sdl/Window.hpp"
#include "client/sdl/SDLErrors.hpp"
#include "client/ClientOptions.hpp"
#include "common/util/ErrorHandler.hpp"

namespace sdl {

    Window::Window() : m_mainWindow{NULL}, m_mainContext{NULL} {
        if (init() != Status::Good) {
            exit(1);
        }
    }

    Window::~Window() {
        SDL_GL_DeleteContext(m_mainContext);
        m_mainContext = NULL;
        SDL_DestroyWindow(m_mainWindow);
        m_mainWindow = NULL;
        SDL_Quit();
    }

    Window::Status Window::init() {
        // Init SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDLErrorHandler::SDLError(SDLErrorMsg::INIT_ERROR);
            return Status::InitFailed;
        }

        // Set OpenGL version to 3.3
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // Create window
        m_mainWindow = SDL_CreateWindow(
                Client::ClientOptions::WINDOW_TITLE.c_str(),
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                Client::ClientOptions::SCREEN_WIDTH,
                Client::ClientOptions::SCREEN_HEIGHT,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (m_mainWindow == NULL) {
            SDLErrorHandler::SDLError(SDLErrorMsg::WINDOW_INIT_ERROR);
            return Status::InitFailed;
        }

        // Create context
        m_mainContext = SDL_GL_CreateContext(m_mainWindow);
        if (m_mainContext == NULL) {
            SDLErrorHandler::SDLError(SDLErrorMsg::CONTEXT_INIT_ERROR);
            return Status::InitFailed;
        }

        // Set OpenGL swap buffer interval
        if (SDL_GL_SetSwapInterval(1) < 0) {
            SDLErrorHandler::SDLError(SDLErrorMsg::VSYNC_INIT_ERROR);
        }

        // Init glad
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
            ErrorHandler::Error(
                        ErrorType::GLAD,
                        ErrorMsg::GLAD_INIT_ERROR
                    );
            return Status::InitFailed;
        }
        if (!gladLoadGL()) {
            ErrorHandler::Error(
                        ErrorType::GLAD,
                        ErrorMsg::GLAD_GL_INIT_ERROR
                    );
            return Status::InitFailed;
        }

        return Status::Good;
    }

    void Window::swapWindow() {
        SDL_GL_SwapWindow(m_mainWindow); 
    }

}

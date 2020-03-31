#include "client/sdl/KeyInput.hpp"
#include "client/state/KeyState.hpp"
#include <SDL.h>
#include <iostream>

namespace sdl {

    void KeyInput::updateState() {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                } else if (m_keyState.find(event.key.keysym.sym)) {
                    m_keyState[event.key.keysym.sym] = true;
                }
            } else if (event.type == SDL_KEYUP) {
                if (m_keyState.find(event.key.keysym.sym)) {
                    m_keyState[event.key.keysym.sym] = false;
                }
            }
        }
    }

    Client::KeyState& KeyInput::getState() {
        return m_keyState;
    }

    bool KeyInput::quit{false};

    Client::KeyState KeyInput::m_keyState{};

}

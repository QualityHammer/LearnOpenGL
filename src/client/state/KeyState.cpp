#include "client/state/KeyState.hpp"

namespace Client {

    const std::vector<SDL_Keycode>
        KeyState::m_keys{{
            SDLK_w,
            SDLK_s,
            SDLK_a,
            SDLK_d,
            SDLK_o,
        }};

    KeyState::KeyState() : state{} {
        for (auto key : m_keys) {
            state[key] = false;
        }
    }

    bool KeyState::find(SDL_Keycode key) const {
        return (state.count(key) > 0);
    }

    void KeyState::resetKey(SDL_Keycode key) {
        state[key] = false;
    }

    bool& KeyState::operator[] (SDL_Keycode key) {
        return state[key];
    }

}

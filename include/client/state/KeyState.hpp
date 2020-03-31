#pragma once
#ifndef KEY_STATE_HPP
#define KEY_STATE_HPP
#include <SDL.h>
#include <unordered_map>
#include <vector>

namespace Client {

    class KeyState {
    public:
        KeyState();
        
        bool find(SDL_Keycode key);
        void resetKey(SDL_Keycode key);

        std::unordered_map<SDL_Keycode, bool> state;

        bool& operator[] (SDL_Keycode key);
    private:
        static const std::vector<SDL_Keycode> m_keys;
    };

}

#endif

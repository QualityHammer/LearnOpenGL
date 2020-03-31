#pragma once
#ifndef KEY_INPUT_HPP
#define KEY_INPUT_HPP

namespace Client {
    class KeyState;
}

namespace sdl {
    class KeyInput {
    public:
        static void updateState();
        static Client::KeyState& getState();

        static bool quit;
    private:
        static Client::KeyState m_keyState;
    };

}

#endif

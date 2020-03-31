#pragma once
#ifndef ENGINE_HPP
#define ENGING_HPP
#include "client/renderer/Renderer.hpp"
#include "client/state/KeyState.hpp"

namespace Client {
    class KeyState;

    class Engine final {
    public:
        enum class Status {
            Running,
            Quit,
            Error
        };

        Engine();

        void runClient();
    private:
        void getKeys();
        void render();

        Status m_status;
        Renderer m_renderer;
        KeyState& m_keyState;
    };

}

#endif

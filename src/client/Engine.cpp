#include "client/Engine.hpp"
#include "client/renderer/Renderer.hpp"
#include "client/sdl/KeyInput.hpp"

#include <iostream>

namespace Client {

    Engine::Engine() : m_renderer{}, 
        m_keyState{sdl::KeyInput::getState()} {}

    void Engine::runClient() {
        m_status = Status::Running;
        while (m_status == Status::Running) {
            getKeys();
            render();
        }
    }

    void Engine::getKeys() {
        sdl::KeyInput::updateState();
        if (sdl::KeyInput::quit)
            m_status = Status::Quit;
        else if (m_keyState[SDLK_o]) {
            m_renderer.toggleWireframe();
            m_keyState.resetKey(SDLK_o);
        }
    }

    void Engine::render() const {
        m_renderer.render();
    }

}

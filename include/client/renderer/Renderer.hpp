#pragma once
#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <vector>

#include "client/gl/Shader.hpp"
#include "client/sdl/Window.hpp"
#include "client/renderer/Model.hpp"

namespace Client {

    class Renderer {
    public:
        enum class Status {
            Good,
            InitFailed,
        };

        Renderer();

        void render();
        void toggleWireframe();
    private:
        Status init();

        sdl::Window m_window;
        gl::Shader m_shader;
        gl::Shader m_newShader;
        std::vector<Model> m_models;
        bool m_wireframe;
    };

}

#endif

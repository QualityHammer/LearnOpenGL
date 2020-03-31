#include <glad/glad.h>
#include <SDL.h>
#include <iostream>
#include <utility>
#include <cmath>

#include "client/ClientOptions.hpp"
#include "client/renderer/Renderer.hpp"
#include "client/sdl/Window.hpp"
#include "common/util/ErrorHandler.hpp"

namespace Client {

    Renderer::Renderer() : m_window{}, m_shader{"simple", "color"}, 
            m_models{}, m_wireframe{false} {
        init();
    }

    Renderer::Status Renderer::init() {
        glViewport(0, 0,
                Client::ClientOptions::SCREEN_WIDTH,
                Client::ClientOptions::SCREEN_HEIGHT);

        std::vector<GLfloat> vertices{{
                -0.5f,  -0.5f, 0.0f,
                 0.0f,  -0.5f, 0.0f,
                -0.25f,  0.5f, 0.0f,
                 0.25f,  0.5f, 0.0f,
                 0.5f,  -0.5f, 0.0f,
        }};
        std::vector<GLuint> indices{{
                0, 1, 2,
                1, 2, 3,
                1, 3, 4
        }};
        
        m_models.push_back(Model{vertices, indices});

        return Status::Good;
    }

    void Renderer::render() const {
        glClearColor(0.2f, 0.3f, 0.4f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_shader.bind();
        int vertColorLocation{glGetUniformLocation(m_shader.ID, "color")};
        glUniform4f(vertColorLocation, 0.0f, 0.5f, 0.0f, 1.0f);

        for (const auto &model : m_models) {
            model.render();
        }
        m_shader.unbind();

        m_window.swapWindow();

        SDL_Delay(10);
    }

    void Renderer::toggleWireframe() {
        m_wireframe = !m_wireframe;
        if (m_wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

}

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

    Renderer::Renderer() : m_window{}, m_shader{"texture", "texture"}, 
            m_models{}, m_wireframe{false} {
        init();
    }

    Renderer::Status Renderer::init() {
        glViewport(0, 0,
                Client::ClientOptions::SCREEN_WIDTH,
                Client::ClientOptions::SCREEN_HEIGHT);

        std::vector<GLfloat> vertices{{
            // positions          // colors           // texture coords
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
        }};
        std::vector<GLuint> indices{{
            0, 1, 2,
            0, 2, 3
        }};
        
        m_models.push_back(gl::TexturedModel{vertices, indices, 
                "assets/textures/grass_side.png"});

        m_shader.bind();
        glUniform1i(glGetUniformLocation(m_shader.ID, "textureData"), 0);

        return Status::Good;
    }

    void Renderer::render() const {
        glClearColor(0.2f, 0.3f, 0.4f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_shader.bind();

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

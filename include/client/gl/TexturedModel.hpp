#pragma once
#ifndef TEXTURED_MODEL_HPP
#define TEXTURED_MODEL_HPP
#include <string>

#include "client/gl/Model.hpp"
#include "client/gl/Texture.hpp"

namespace gl {

    class TexturedModel {
        public:
            TexturedModel(const std::vector<GLfloat>& vertices,
                    const std::vector<GLuint>& indices,
                    const std::string& textureFileName);
            TexturedModel(const TexturedModel& other);
            TexturedModel(TexturedModel&& other);

            void render() const;
            int size() const;

            TexturedModel& operator=(const TexturedModel& other);
            TexturedModel& operator=(TexturedModel&& other);
        private:
            Model m_model;
            Texture m_texture;

            void bind() const;
            void unbind() const;
    };

}

#endif

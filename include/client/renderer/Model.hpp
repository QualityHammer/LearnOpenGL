#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>

#include "client/gl/VertexArray.hpp"

namespace Client {

    class Model {
        public:
            Model(const std::vector<GLfloat>& vertices,
                    const std::vector<GLuint>& indices);
            Model(const Model& other);
            Model(Model&& other);

            void render() const;
            int size() const;

            Model& operator=(const Model& other);
            Model& operator=(Model&& other);
        private:
            gl::VertexArray m_vertexArray;

            void bind() const;
            void unbind() const;
    };

}

#endif

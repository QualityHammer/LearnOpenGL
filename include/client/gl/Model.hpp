#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>

#include "client/gl/VertexArray.hpp"

namespace gl {

    class Model {
        public:
            Model();
            Model(const std::vector<GLfloat>& vertices,
                    const std::vector<GLuint>& indices);
            Model(const Model& other);
            Model(Model&& other);

            void bind() const;
            void unbind() const;
            void render() const;
            int size() const;

            Model& operator=(const Model& other);
            Model& operator=(Model&& other);
        private:
            VertexArray m_vertexArray;
    };

}

#endif

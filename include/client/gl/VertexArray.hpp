#pragma once
#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP
#include <glad/glad.h>
#include <vector>

namespace gl {

    class VertexArray {
        public:
            VertexArray();
            VertexArray(const std::vector<GLfloat>& vertices,
                    const std::vector<GLuint>& indices);
            VertexArray(const VertexArray& other);
            VertexArray(VertexArray&& other);
            ~VertexArray();

            void bind() const;
            int size() const;
            void unbind() const;

            VertexArray& operator=(const VertexArray& other);
            VertexArray& operator=(VertexArray&& other);
        private:
            GLuint ID;
            std::vector<GLuint> m_buffers;
            std::vector<GLuint> m_indices;
            int m_indexCount;
            bool m_copyExists;

            void addVBO(const std::vector<GLfloat>& vertices);
            void addEBO(const std::vector<GLuint>& indices);
    };

}

#endif

#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include "client/gl/VertexArray.hpp"

namespace gl {

    VertexArray::VertexArray() : ID{0}, m_buffers{}, m_indices{}, 
            m_indexCount{0}, m_copyExists{false} {}

    VertexArray::VertexArray(const std::vector<GLfloat>& vertices,
            const std::vector<GLuint>& indices)
            : m_buffers{}, m_indices{}, m_indexCount{0},
            m_copyExists{false} {
        glGenVertexArrays(1, &ID);
        bind();
        addVBO(vertices);
        addEBO(indices);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
                5 * sizeof(GLfloat), (GLvoid*) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
                5 * sizeof(GLfloat), (GLvoid*) (3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        unbind();
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    VertexArray::VertexArray(const VertexArray& other) 
            : ID{other.ID}, m_buffers{}, m_indices{},
            m_indexCount{other.m_indexCount},
            m_copyExists{true} {
        std::copy(other.m_buffers.begin(), other.m_buffers.end(),
                std::back_inserter(m_buffers));
        std::copy(other.m_indices.begin(), other.m_indices.end(),
                std::back_inserter(m_indices));
    }

    VertexArray::VertexArray(VertexArray&& other)
            : ID{0}, m_buffers{}, m_indices{},
            m_indexCount{0}, m_copyExists{true} {
        std::swap(ID, other.ID);
        std::swap(m_buffers, other.m_buffers);
        std::swap(m_indices, other.m_indices);
        std::swap(m_indexCount, other.m_indexCount);
    }

    VertexArray::~VertexArray() {
        if (!m_copyExists) {
            glDeleteVertexArrays(1, &ID);
            glDeleteBuffers(m_buffers.size(), m_buffers.data());
            glDeleteBuffers(m_indices.size(), m_indices.data());
        }
        m_indexCount = 0;
    }

    void VertexArray::addVBO(const std::vector<GLfloat>& vertices) {
        GLuint VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat),
                vertices.data(), GL_STATIC_DRAW);

        m_buffers.push_back(VBO);
    }

    void VertexArray::addEBO(const std::vector<GLuint>& indices) {
        GLuint EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
                indices.data(), GL_STATIC_DRAW);

        m_indexCount += indices.size();
        m_indices.push_back(EBO);
    }

    void VertexArray::bind() const {
        glBindVertexArray(ID);
    }

    int VertexArray::size() const {
        return m_indexCount;
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }

    VertexArray& VertexArray::operator=(const VertexArray& other) {
        VertexArray tmp{other};
        std::swap(ID, tmp.ID);
        std::swap(m_buffers, tmp.m_buffers);
        std::swap(m_indices, tmp.m_indices);
        std::swap(m_indexCount, tmp.m_indexCount);
        m_copyExists = true;
        return *this;
    }

    VertexArray& VertexArray::operator=(VertexArray&& other) {
        std::swap(ID, other.ID);
        std::swap(m_buffers, other.m_buffers);
        std::swap(m_indices, other.m_indices);
        std::swap(m_indexCount, other.m_indexCount);
        m_copyExists = true;
        return *this;
    }

}

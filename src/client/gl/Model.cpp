#include <iostream>
#include "client/gl/Model.hpp"

namespace gl {

    Model::Model() : m_vertexArray{} {}

    Model::Model(const std::vector<GLfloat>& vertices,
            const std::vector<GLuint>& indices)
            : m_vertexArray{vertices, indices} {}

    Model::Model(const Model& other) 
            : m_vertexArray{other.m_vertexArray} {}

    Model::Model(Model&& other)
            : m_vertexArray{} {
        std::swap(m_vertexArray, other.m_vertexArray);
    }

    void Model::bind() const {
        m_vertexArray.bind();
    }

    void Model::render() const {
        bind();
        glDrawElements(GL_TRIANGLES, m_vertexArray.size(), GL_UNSIGNED_INT, 0);
        unbind();
    }

    int Model::size() const {
        return m_vertexArray.size();
    }

    void Model::unbind() const {
        m_vertexArray.unbind();
    }

    Model& Model::operator=(const Model& other) {
        Model tmp{other};
        std::swap(m_vertexArray, tmp.m_vertexArray);
        return *this;
    }
    
    Model& Model::operator=(Model&& other) {
        std::swap(m_vertexArray, other.m_vertexArray);
        return *this;
    }

}

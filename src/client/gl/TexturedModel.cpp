#include "client/gl/TexturedModel.hpp"

namespace gl {

    TexturedModel::TexturedModel(const std::vector<GLfloat>& vertices,
            const std::vector<GLuint>& indices,
            const std::string& textureFileName) 
            : m_model{vertices, indices}, m_texture{textureFileName} {}

    TexturedModel::TexturedModel(const TexturedModel& other) 
            : m_model{other.m_model}, m_texture{other.m_texture} {}

    TexturedModel::TexturedModel(TexturedModel&& other)
            : m_model{}, m_texture{} {
        std::swap(m_model, other.m_model);
        std::swap(m_texture, other.m_texture);
    }

    void TexturedModel::render() const {
        bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        unbind();
    }

    int TexturedModel::size() const {
        return m_model.size();
    }

    TexturedModel& TexturedModel::operator=(const TexturedModel& other) {
        TexturedModel tmp{other};
        std::swap(m_model, tmp.m_model);
        std::swap(m_texture, tmp.m_texture);
        return *this;
    }

    TexturedModel& TexturedModel::operator=(TexturedModel&& other) {
        std::swap(m_model, other.m_model);
        std::swap(m_texture, other.m_texture);
        return *this;
    }

    void TexturedModel::bind() const {
        m_texture.bind();
        m_model.bind();
    }

    void TexturedModel::unbind() const {
        m_model.unbind();
        m_texture.unbind();
    }

}

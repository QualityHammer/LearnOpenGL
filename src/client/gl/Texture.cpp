#include <glad/glad.h>
#include <utils/stb_image.h>

#include "client/gl/Texture.hpp"
#include "client/gl/Image.hpp"
#include "common/util/ErrorHandler.hpp"

namespace gl {

    Texture::Texture() : ID{0} {}

    Texture::Texture(const std::string& filename) {
        loadImg(filename);
    }

    void Texture::bind() const {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void Texture::loadImg(const std::string& filename) {
        glGenTextures(1, &ID);
        Image img{loadImage(filename)};
        bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width,
                img.height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                img.data);
        glGenerateMipmap(GL_TEXTURE_2D);
        if (img.data == nullptr)
            ErrorHandler::Error(ErrorType::IMAGE, ErrorMsg::IMAGE_LOAD_ERROR);
    }

    void Texture::unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}

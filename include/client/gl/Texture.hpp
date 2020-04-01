#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <string>

namespace gl {

    class Texture {
        public:
            Texture();
            Texture(const std::string& filename);

            void bind() const;
            void unbind() const;
        private:
            void loadImg(const std::string& filename);

            GLuint ID;
    };

}

#endif

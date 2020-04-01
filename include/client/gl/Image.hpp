#pragma once
#ifndef IMAGE_LOAD_HPP
#define IMAGE_LOAD_HPP
#define STB_IMAGE_IMPLEMENTATION
#include <string>

namespace gl {

    struct Image {
        unsigned char* data;
        int width, height, nrChannels;
    };

    Image loadImage(const std::string& filename);

}

#endif

#include "client/gl/Image.hpp"
#include <utils/stb_image.h>

namespace gl {

    Image loadImage(const std::string& filename) {
        Image img;
        stbi_set_flip_vertically_on_load(true);
        img.data = stbi_load(filename.c_str(), &img.width,
                &img.height, &img.nrChannels, 0);
        return img;
    }

}

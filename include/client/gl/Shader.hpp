#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP
#include <string>
#include <glad/glad.h>

namespace gl {

    class Shader {
    public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);

        void bind();
        void unbind();

        GLuint ID;
    private:
        void init(const std::string &vertexPath, const std::string &fragmentPath);
    };

}

#endif

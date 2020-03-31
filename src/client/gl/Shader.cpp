#include <fstream>
#include <sstream>
#include <iostream>

#include "client/gl/Shader.hpp"
#include "client/gl/GLErrors.hpp"
#include "common/util/ErrorHandler.hpp"

namespace gl {

    Shader::Shader(const std::string &vertexPath, 
            const std::string &fragmentPath) {
        init(vertexPath, fragmentPath);
    }

    void Shader::init(const std::string &vertexPath, 
            const std::string &fragmentPath) {
        const std::string vFullPath{"shaders/" +
            vertexPath + "_vertex.glsl"};
        const std::string fFullPath{"shaders/" +
            fragmentPath + "_fragment.glsl"};
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit 
                | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit 
                | std::ifstream::badbit);
        try {
            vShaderFile.open(vFullPath);
            fShaderFile.open(fFullPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        } catch (std::ifstream::failure e) {
            ErrorHandler::Error(
                    ErrorType::SHADER,
                    ErrorMsg::FILE_READ_ERROR);
        }
        const char* vShaderCode{vertexCode.c_str()};
        const char* fShaderCode{fragmentCode.c_str()};

        GLuint vertex, fragment;
        constexpr int logSize{512};
        char infoLog[logSize];
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkShaderCompile(vertex, GLErrorType::VERTEX,
                infoLog, logSize);
        
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkShaderCompile(fragment, GLErrorType::FRAGMENT,
                infoLog, logSize);

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkShaderLink(ID, infoLog, logSize);

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void Shader::bind() {
        glUseProgram(ID);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }
    
}

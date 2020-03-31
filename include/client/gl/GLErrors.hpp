#pragma once
#ifndef GL_ERRORS_HPP
#define GL_ERRORS_HPP
#include <glad/glad.h>

namespace gl {

    enum class GLErrorType : unsigned int {
        VERTEX,             // 0
        FRAGMENT,           // 2
        PROGRAM,            // 3
        TYPE_COUNT          // Number of error types
    };

    void checkShaderCompile(const GLuint shader, 
            const GLErrorType glType, char *infoLog, const int logSize);
    void checkShaderLink(const GLuint program,
            char *infoLog, const int logSize);

}

#endif

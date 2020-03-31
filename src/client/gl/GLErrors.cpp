#include "common/util/ErrorHandler.hpp"
#include "client/gl/GLErrors.hpp"

namespace gl {

    void checkShaderCompile(const GLuint shader,
            const GLErrorType glType, char *infoLog, const int logSize) {
        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, logSize, NULL, infoLog);
            ErrorHandler::GLError(ErrorType::SHADER,
                    ErrorMsg::COMPILATION_ERROR, glType, 
                    infoLog);
        }
    }

    void checkShaderLink(const GLuint program,
            char *infoLog, const int logSize) {
        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, logSize, NULL, infoLog);
            ErrorHandler::GLError(ErrorType::SHADER,
                    ErrorMsg::LINKING_ERROR,
                    GLErrorType::PROGRAM,
                    infoLog);
        }
    }

}

#pragma once
#ifndef ERROR_HANDLER_HPP
#define ERROR_HANDLER_HPP
#include <array>
#include <string>

#include "client/gl/GLErrors.hpp"

enum class ErrorType : unsigned int {
    GLAD,               // 0
    SHADER,             // 1
    IMAGE,              // 2
    TYPE_COUNT          // Number of error types
};

enum class ErrorMsg : unsigned int {
    GLAD_INIT_ERROR,    // 0
    FILE_READ_ERROR,    // 1
    COMPILATION_ERROR,  // 2
    LINKING_ERROR,      // 3
    GLAD_GL_INIT_ERROR, // 4
    IMAGE_LOAD_ERROR,   // 5
    MSG_COUNT           // Number of error messages
};

class ErrorHandler {
public:
    static void Error(const ErrorType eType, const ErrorMsg msg);
    static void GLError(const ErrorType eType, const ErrorMsg msg,
            const gl::GLErrorType glType, const char* infoLog);
private:
    static const std::array<std::string, 
            static_cast<unsigned int>(ErrorType::TYPE_COUNT)>
            m_errorTypeStrings;
    static const std::array<std::string,
            static_cast<unsigned int>(ErrorMsg::MSG_COUNT)>
            m_errorMsgStrings;
    static const std::array<std::string,
            static_cast<unsigned int>(gl::GLErrorType::TYPE_COUNT)>
            m_glErrorTypeStrings;
};

#endif

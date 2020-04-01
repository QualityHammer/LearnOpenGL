#include <iostream>

#include "common/util/ErrorHandler.hpp"

const std::array<std::string, 
        static_cast<unsigned int>(ErrorType::TYPE_COUNT)>
        ErrorHandler::m_errorTypeStrings{{
            "Glad",
            "Shader",
            "Image",
        }};

const std::array<std::string,
        static_cast<unsigned int>(ErrorMsg::MSG_COUNT)>
        ErrorHandler::m_errorMsgStrings{{
            "Glad failed to initialize!",
            "File read unsuccessful.",
            "Compilation failed!",
            "Linking failed!",
            "Glad failed to initialize OpenGL!",
            "Failed to load image.",
        }};

const std::array<std::string,
        static_cast<unsigned int>(gl::GLErrorType::TYPE_COUNT)>
        ErrorHandler::m_glErrorTypeStrings{{
            "Vertex",
            "Fragment",
            "Program",
        }};

void ErrorHandler::Error(const ErrorType eType, const ErrorMsg msg) {
    std::cerr << "Error::"
              << m_errorTypeStrings[static_cast<unsigned int>(eType)]
              << ": "
              << m_errorMsgStrings[static_cast<unsigned int>(msg)]
              << std::endl;
}

void ErrorHandler::GLError(const ErrorType eType, const ErrorMsg msg,
        const gl::GLErrorType glType, const char* infoLog) {
    std::cerr << "Error::"
              << m_glErrorTypeStrings[static_cast<unsigned int>(glType)]
              << "::"
              << m_errorTypeStrings[static_cast<unsigned int>(eType)]
              << ": "
              << m_errorMsgStrings[static_cast<unsigned int>(msg)]
              << std::endl
              << infoLog << std::endl;
}

cmake_minimum_required(VERSION 3.16)

project(learn-opengl VERSION 1.0)

add_executable(${PROJECT_NAME}
    src/Game.cpp
    src/client/Engine.cpp
    src/client/gl/Shader.cpp
    src/client/gl/Image.cpp
    src/client/gl/Texture.cpp
    src/client/gl/GLErrors.cpp
    src/client/gl/VertexArray.cpp
    src/client/gl/Model.cpp
    src/client/gl/TexturedModel.cpp
    src/client/renderer/Renderer.cpp
    src/client/state/KeyState.cpp
    src/client/sdl/Window.cpp
    src/client/sdl/KeyInput.cpp
    src/client/sdl/SDLErrors.cpp
    src/common/util/ErrorHandler.cpp
    src/Main.cpp
)

set(
    CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake_modules"
    ${CMAKE_MODULE_PATH}
)

target_compile_features(${PROJECT_NAME}
    PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_EXTENSIONS OFF
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
    -Wall
    -Wextra
    -Wshadow
    -Wpointer-arith
    -pedantic
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${SDL2_INCLUDE_DIR}
)

find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)

add_subdirectory(dependencies)

target_link_libraries(${PROJECT_NAME}
    glad
    ${SDL2_LIBRARY}
)

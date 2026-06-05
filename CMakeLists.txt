cmake_minimum_required(VERSION 3.28.3)

project(low_fi VERSION 1.0.0 LANGUAGES C CXX)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

# Use local GLFW source
add_subdirectory(dependencies/glfw-3.4)

add_executable(low_fi
    src/main.cpp
    src/glad.c
    src/config.h
    src/config.cpp

    src/helpers/shader.cpp
    src/helpers/triangle.cpp
    src/helpers/input.cpp
    src/helpers/helper.cpp
    src/helpers/camera.cpp
    src/helpers/texture.cpp
)

target_include_directories(low_fi PRIVATE
    dependencies
    dependencies/glfw-3.4/include
    src
    src/helpers
)

target_compile_definitions(low_fi PRIVATE
    ROOT_FOLDER="${CMAKE_SOURCE_DIR}"
)

target_link_libraries(low_fi PRIVATE
    glfw
    OpenGL::GL
)
cmake_minimum_required(VERSION 3.28.3)
project(low_fi VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(low_fi
    src/main.cpp
    src/glad.c
    src/helpers/shader.cpp
    src/helpers/triangle.cpp
    src/helpers/input.cpp
    src/helpers/helper.cpp
)

target_include_directories(low_fi PRIVATE 
    dependencies
    src
    src/helpers
    
)

target_compile_definitions(low_fi PRIVATE ROOT_FOLDER="${CMAKE_SOURCE_DIR}")

target_link_libraries(low_fi glfw OpenGL::GL)
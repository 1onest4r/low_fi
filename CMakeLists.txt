cmake_minimum_required(VERSION 3.28.3)
project(thee VERSION 1.0.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(thee
    src/main.cpp
    src/glad.c
)

target_include_directories(thee PRIVATE 
    dependencies
    
)

target_link_libraries(thee glfw OpenGL::GL)
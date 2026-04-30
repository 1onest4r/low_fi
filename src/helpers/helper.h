#pragma once
#include "config.h"

class Context
{
public:
    Context();

    GLFWwindow *createContext(int width, int height, std::string name);

private:
    GLFWwindow *window;
    int width;
    int height;
};
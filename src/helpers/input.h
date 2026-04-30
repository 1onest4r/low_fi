#pragma once
#include "config.h"

class Camera; // literally u can use it just like that

class Input
{
public:
    void processInput(GLFWwindow *window, float deltaTime);
    void setActiveCamera(Camera *camera);
};
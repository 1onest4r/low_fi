#include "input.h"
#include "helpers/camera.h"

// hot reload stuffs
static bool reloadPressedLastFrame = false;
static bool reloadRequested = false;

static Camera *cameraPtr = nullptr;

void setActiveCamera(Camera *camera)
{
    cameraPtr = camera;
}

void processInput(GLFWwindow *window, float deltaTime)
{
    if (!cameraPtr)
        return;

    // keyboard input logic
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // hot reaload toggle
    bool reloadPressed = glfwGetKey(window, GLFW_KEY_F5) == GLFW_PRESS;

    if (reloadPressed && !reloadPressedLastFrame)
    {
        reloadRequested = true;
    }

    reloadPressedLastFrame = reloadPressed;
}

bool consumeShaderReloadRequest()
{
    if (reloadRequested)
    {
        reloadRequested = false;
        return true;
    }
    return false;
}
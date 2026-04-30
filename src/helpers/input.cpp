#include "input.h"
#include "helpers/camera.h"

static Camera *cameraPtr = nullptr;

void Input::setActiveCamera(Camera *camera)
{
    cameraPtr = camera;
}

void Input::processInput(GLFWwindow *window, float deltaTime)
{
    if (!cameraPtr)
        return;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPtr->processKeyboard(FORWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPtr->processKeyboard(BACKWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPtr->processKeyboard(RIGHT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPtr->processKeyboard(LEFT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

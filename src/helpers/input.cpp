#include "input.h"
#include "helpers/camera.h"

static float lastX = 360.0f;
static float lastY = 480.0f;
static float sensitivity = 0.7f;

static Camera *cameraPtr = nullptr;
static bool mouseLocked = false;
static bool togglePressedLastFrame = false;
static bool firstMouse = true;

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

    bool togglePressed = glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS;

    if (togglePressed && !togglePressedLastFrame)
    {
        mouseLocked = !mouseLocked;

        glfwSetInputMode(window, GLFW_CURSOR, mouseLocked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);

        if (mouseLocked)
        {
            if (glfwRawMouseMotionSupported())
            {
                glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
            }
        }
        else
        {
            glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
        }

        // avoids jump?
        firstMouse = true;
    }

    togglePressedLastFrame = togglePressed;
    if (mouseLocked)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        if (firstMouse)
        {
            lastX = (float)xpos;
            lastY = (float)ypos;
            firstMouse = false;
        }

        float xOffset = (float)xpos - lastX;
        float yOffset = lastY - (float)ypos;

        xOffset *= sensitivity;
        yOffset *= sensitivity;

        lastX = (float)xpos;
        lastY = (float)ypos;

        cameraPtr->processMouseMovement(xOffset, yOffset);
    }
}

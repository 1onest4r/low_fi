#include "camera.h"

Camera::Camera(glm::vec3 startPos)
    : position(startPos)
{
    updateVectors();
}

glm::mat4 Camera::getViewMatrix()
{
    return;
}

void Camera::processKeyboard(float deltaTime)
{
}

void Camera::processMouseMovement(float xOffset, float yOffset)
{
    updateVectors();
}

void Camera::updateVectors()
{
}
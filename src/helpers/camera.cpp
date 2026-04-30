#include "camera.h"

Camera::Camera(glm::vec3 startPos)
    : position(startPos),
      forward(0.0f, 0.0f, -1.0f),
      worldUp(0.0f, 1.0f, 0.0f),
      yaw(-90.0f),
      pitch(0.0f),
      speed(2.5f),
      sensitivity(0.1f)

{
    updateVectors();
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(
        position,
        position + forward,
        up);
}

void Camera::processKeyboard(CameraMovement movement, float deltaTime)
{
    float velocity = speed * deltaTime;

    if (movement == FORWARD)
        position += forward * velocity;

    if (movement == BACKWARD)
        position -= forward * velocity;

    if (movement == RIGHT)
        position += right * velocity;

    if (movement == LEFT)
        position -= right * velocity;
}

void Camera::processMouseMovement(float xOffset, float yOffset)
{
}

void Camera::updateVectors()
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw) * cos(glm::radians(pitch)));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw) * cos(glm::radians(pitch)));

    forward = glm::normalize(direction);
    right = glm::normalize(glm::cross(forward, worldUp));
    up = glm::normalize(glm::cross(forward, right));
}
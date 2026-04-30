#pragma once
#include "config.h"

enum CameraMovement
{
    FORWARD,
    BACKWARD,
    RIGHT,
    LEFT,
};

class Camera
{
public:
    glm::vec3 position, forward, up, right, worldUp;
    float speed, yaw, pitch, sensitivity;

    Camera(glm::vec3 startPosition);

    glm::mat4 getViewMatrix();
    void processKeyboard(CameraMovement movement, float deltaTime);
    void processMouseMovement(float xOffset, float yOffset);

private:
    void updateVectors();
};
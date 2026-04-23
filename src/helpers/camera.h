#pragma once
#include "config.h"

class Camera
{
public:
    glm::vec3 position;

    Camera(glm::vec3 startPos);

    glm::mat4 getViewMatrix();
    void processKeyboard(float deltaTime);
    void processMouseMovement(float xOffset, float yOffset);

private:
    void updateVectors();
};
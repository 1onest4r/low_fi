#version 330 core

layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 texCoord;
out vec3 vertCol;

uniform mat4 view;
uniform mat4 proj;
uniform mat4 model;

void main() {
    gl_Position = proj * view * model * vec4(vertPos, 1.0);
    vertCol = aCol;
}
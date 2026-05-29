#version 330 core

layout (location = 0) in vec3 vertPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 texCoord;

out vec3 vertCol;
out vec2 texPos;

uniform mat4 view;
uniform mat4 proj;
uniform mat4 model;
uniform float time;

//along y axis

void main() {
    float a = time;
    float c = cos(a);
    float s = sin(a);

    mat3 Ry = mat3(
        c, 0.0, s,
        0.0, 1.0, 0.0,
        -s, 0.0, c
    );

    vec3 rotated = Ry * vertPos;

    gl_Position = proj * view * model * vec4(rotated, 1.0);
    vertCol = aCol;
    texPos = vec2(1.0, -1.0) * texCoord;
}
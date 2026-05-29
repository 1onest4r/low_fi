#version 330 core

in vec3 vertCol;
in vec2 texPos;
out vec4 FragColor;

uniform float time;
uniform sampler2D texture1;

void main()
{
    // vec3 col;
    // float a = (cos(time * 2.0) + 1.0) / 2.0; // make sure it falls under [0, 1] range
    // col = vec3(a, vertCol.g, vertCol.b);

    FragColor = texture(texture1, texPos);
} 
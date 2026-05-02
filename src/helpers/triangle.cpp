#include "triangle.h"

Triangle::Triangle()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // 0
        0.5f, -0.5f, 0.0f,  // 1
        -0.5f, 0.5f, 0.0f,  // 2
        0.5f, 0.5f, 0.0f,   // 3
    };

    float colors[] = {
        1.0f, 0.0f, 0.0f, // 0
        0.0f, 1.0f, 0.0f, // 1
        0.0f, 0.0f, 1.0f, // 2
    };

    unsigned int indices[] = {
        0, 1, 2,
        3, 1, 2
    };

    float textCoords[] = {
        0.0f, 0.0f, // left bottom
        0.0f, 1.0f, // left top
        1.0f, 1.0f, // right top
        1.0f, 0.0f  // right bottom 
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VBOs.resize(2);
    glGenBuffers(2, VBOs.data());
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // unbind the VAO so that accidental editing wont gonna happen
    glBindVertexArray(0);
}

void Triangle::draw()
{
    glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Triangle::~Triangle()
{
    glDeleteBuffers(VBOs.size(), VBOs.data());
    glDeleteVertexArrays(1, &VAO);
}
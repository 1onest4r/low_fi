#pragma once
#include "config.h"

class Triangle
{
public:
    Triangle();
    ~Triangle();

    void draw();

private:
    unsigned int VAO;
    unsigned int EBO;
    std::vector<unsigned int> VBOs;
};
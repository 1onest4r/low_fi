#pragma once

#include "config.h"

class Shader
{
public:
    Shader(
        const std::string &name,
        const std::string &vertexPath,
        const std::string &fragmentPath);
    void use();

    GLuint id() const { return shaderId; };

private:
    std::string shaderName;

    std::string vertexPath;
    std::string fragmentPath;

    GLuint shaderId;

    GLuint makeShader(const std::string &shaderPath, unsigned int shaderType);
    GLuint linkShader();
};
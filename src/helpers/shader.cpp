#include "shader.h"
#include "config.h"

Shader::Shader(
    const std::string &name,
    const std::string &vertexPath,
    const std::string &fragmentPath) : shaderName(name),
                                       vertexPath(vertexPath),
                                       fragmentPath(fragmentPath)
{
    std::cout << "Shader: " << shaderName << " created" << std::endl;
}

GLuint Shader::makeShader(const std::string &shaderPath, GLuint shaderType)
{
    std::ifstream file(shaderPath);
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string src = buffer.str();
    const char *shaderSrc = src.c_str();

    for (int i = 0; i < src.size(); ++i)
    {
        std::cout << src[i];
    }

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSrc, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << shaderType << " shader compilition error: " << infoLog << std::endl;
    }

    return shader;
}

GLuint Shader::linkShader()
{
    GLuint vert = makeShader(vertexPath, GL_VERTEX_SHADER);
    GLuint frag = makeShader(fragmentPath, GL_FRAGMENT_SHADER);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vert);
    glAttachShader(shaderProgram, frag);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader linking error: " << infoLog << std::endl;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);

    return shaderProgram;
}

void Shader::use()
{
    glUseProgram(shaderId);
}
#include "helper.h"

Context::Context()
{
    glfwInit(); // for initializing

    // simply specifying the 3.3 and to use core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // load glad to use actual supported gl functions that are OS specifi?
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

GLFWwindow *createContext(int width, int height, std::string name)
{
    const char *name_c = name.c_str();
    return glfwCreateWindow(width, height, name_c, NULL, NULL);
}
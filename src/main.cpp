#include "config.h"
#include "shader.h"
#include "triangle.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    std::string shaderDir = std::string(ROOT_FOLDER) + "/src/shaders/";

    // for initializing glfw col
    glfwInit();

    // these are for telling the system that use at least 3.3 and use core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create the window after initializing the glfw
    GLFWwindow *window = glfwCreateWindow(800, 600, "Thee", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // load glad to use actual supported gl functions that are OS specifi?
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader triangle(
        "triangle",
        shaderDir + "triangle.vert",
        shaderDir + "triangle.frag");

    Triangle tri;

    glViewport(0, 0, 800, 600);
    // this one is for resizing the window and its a callback col
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    float delta, lastFrame = 0.0f;
    int timeLoc = glGetUniformLocation(triangle.id(), "time"); // is expensive to do it everyframe so here

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        delta = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.use(); // make sure to use the shader program and then update the uniform value
        glUniform1f(timeLoc, currentFrame);

        tri.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

#include "config.h"
#include "shader.h"
#include "triangle.h"
#include "input.h"
#include "helper.h"
#include "camera.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height);

int main()
{
    std::string shaderDir = std::string(ROOT_FOLDER) + "/src/shaders/";
    Input input;
    Context context;
    Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    GLFWwindow *window = context.createContext(800, 600, "low_fi");
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    context.initGlad(); // init glad only after making context

    Shader triangle(
        "triangle",
        shaderDir + "triangle.vert",
        shaderDir + "triangle.frag");

    glViewport(0, 0, 800, 600);
    // this one is for resizing the window and its a callback col
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    input.setActiveCamera(&camera);

    float delta, lastFrame = 0.0f;
    int timeLoc;
    if (triangle.id() == -1)
    {
        std::cout << "Failed to retrieve shader id" << std::endl;
    }
    else
    {
        timeLoc = glGetUniformLocation(triangle.id(), "time"); // is expensive to do it everyframe so here
    }

    { // for the buffer to clean up before the context termination using another scope
        Triangle tri;

        while (!glfwWindowShouldClose(window))
        {
            float currentFrame = glfwGetTime();
            delta = currentFrame - lastFrame;
            lastFrame = currentFrame;

            input.processInput(window, delta);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            triangle.use(); // make sure to use the shader program and then update the uniform value
            glUniform1f(timeLoc, currentFrame);

            tri.draw();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    input.setActiveCamera(nullptr);
    glfwTerminate();

    return 0;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

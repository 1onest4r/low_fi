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
    glm::mat4 model = glm::mat4(1.0f);
    float fov = 45.0f;
    int screenWidth = 800;
    int screenHeight = 600;
    GLFWwindow *window = context.createContext(screenWidth, screenHeight, "low_fi");

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

    // glViewport(0, 0, screenWidth, screenHeight);
    // this one is for resizing the window and its a callback col
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    input.setActiveCamera(&camera);

    float delta, lastFrame = 0.0f;
    int timeLoc;
    int modelLoc;
    int viewLoc;
    int projLoc;
    if (triangle.id() == -1)
    {
        std::cout << "Failed to retrieve shader id" << std::endl;
    }
    else
    {
        timeLoc = glGetUniformLocation(triangle.id(), "time");  
        modelLoc = glGetUniformLocation(triangle.id(), "model");
        viewLoc = glGetUniformLocation(triangle.id(), "view");  
        projLoc = glGetUniformLocation(triangle.id(), "proj");   
    }

    { // for the buffer to clean up before the context termination using another scope
        Triangle tri;

        while (!glfwWindowShouldClose(window))
        {
            float currentFrame = glfwGetTime();
            delta = currentFrame - lastFrame;
            lastFrame = currentFrame;

            glm::mat4 proj = glm::perspective(glm::radians(fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
            glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

            input.processInput(window, delta);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            triangle.use(); // make sure to use the shader program and then update the uniform value
            glm::mat4 view = camera.getViewMatrix();
            glUniform1f(timeLoc, currentFrame);
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

            tri.draw();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    input.setActiveCamera(nullptr);
    glfwTerminate();

    return 0;
}

void framebufferSizeCallback(GLFWwindow *window, int screenWidth, int screenHeight)
{
    glViewport(0, 0, screenWidth, screenHeight);
}

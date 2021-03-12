#include "index.h"

void Log(const char *message)
{
    std::cout << message << std::endl;
}

helperFunction ::helperFunction(int height, int width, const char *title)
{
    windowHeight = width;
    windowWidth = height;

    if (!glfwInit())
        Log("Failure to initialize glfw");

    window = glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if (!window)
    {
        glfwTerminate();
        Log("Window cration failure");
        return;
    }
}

void helperFunction ::Gladinitialization()
{

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failure to initialize glad");
        return;
    }
}

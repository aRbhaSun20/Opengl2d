#include "index.h"

Initialize ::Initialize(int width, int height, const char *title)
:windowHeight(height),windowWidth(width)
{
    if (!glfwInit())
        Log("Failure to initialize glfw");

   m_window = glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if (!m_window)
    {
        glfwTerminate();
        Log("Window cration failure");
        return;
    }
}

Initialize ::~Initialize()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Initialize ::Gladinitialization()
{

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Failure to initialize glad");
        return;
    }
}

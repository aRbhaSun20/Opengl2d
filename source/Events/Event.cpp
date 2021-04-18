#include "Event.h"

void Event::Event_Keyboard_Callback()
{
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        // glfwWindowShouldClose(m_Window, GL_TRUE);
        glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
    }
    if (glfwGetKey(m_Window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::FORWARD, m_Timestep.GetSeconds());
    }

    if (glfwGetKey(m_Window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::BACKWARD, m_Timestep.GetSeconds());
    }
    if (glfwGetKey(m_Window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::LEFT, m_Timestep.GetSeconds());
    }
    if (glfwGetKey(m_Window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::RIGHT, m_Timestep.GetSeconds());
    }
    if (glfwGetKey(m_Window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::UP, m_Timestep.GetSeconds());
    }

    if (glfwGetKey(m_Window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        m_View.ProcessKeyboard(Camera_Movement::DOWN, m_Timestep.GetSeconds());
    }
}

void Event::Event_Mouse_Callback()
{
    double xpos, ypos;

    glfwGetCursorPos(m_Window, &xpos, &ypos);

    float sensitivity = 0.15f;

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xOffset = (xpos - lastX);
    float yOffset = (lastY - ypos);

    lastX = xpos;
    lastY = ypos;

    m_View.ProcessMouseMovement(xOffset, yOffset);
}
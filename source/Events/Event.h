#pragma once

#include <GLFW/glfw3.h>

#include "../Camera/PerspectiveCamera.h"
#include "../Core/Timestep.h"

class Event
{
private:
    GLFWwindow *m_Window;
    PerspectiveCamera &m_View;
    Timestep &m_Timestep;

    int WIDTH;
    int HEIGHT;
    float lastX;
    float lastY;
    bool firstMouse = true;

public:
    Event(GLFWwindow *window, PerspectiveCamera &View, Timestep &timestep, int width, int height)
        : m_Window(window), WIDTH(width), HEIGHT(height), lastX(WIDTH / 2.0), lastY(HEIGHT / 2.0),
          m_View(View), m_Timestep(timestep){};

    void Event_Keyboard_Callback();

    void Event_Mouse_Callback();

    void Event_MouseScroll_Callback()
    {
        float yoffset;
        m_View.ProcessMouseScroll(yoffset);
    }

    // void scrollHandler(int yoffset){
        
    // }
};

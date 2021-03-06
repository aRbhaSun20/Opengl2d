#pragma once

// external libraries and packages

#include "precomz.h"
class Initialize
{
private:
    int windowWidth, windowHeight;
    GLFWwindow *m_window;

public:
    Initialize(int, int, const char *);
    GLFWwindow *getWindowReference() { return m_window; }
    void Gladinitialization();
    ~Initialize();

private:
    static void error_callback(int error, const char *description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    static void framebuffer_size(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
};
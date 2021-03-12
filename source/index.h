#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

void Log(const char *message);

class helperFunction
{
private:
    int windowWidth, windowHeight;

public:
    GLFWwindow *window;
    helperFunction(int height, int width, const char *title);

    void Gladinitialization();
};

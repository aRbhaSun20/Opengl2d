#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Shaders/ShaderInitialize.h"

void Log(const char *message);

class Initialize
{
private:
    int windowWidth, windowHeight;

public:
    GLFWwindow *window;
    Initialize(int height, int width, const char *title);

    void Gladinitialization();
};



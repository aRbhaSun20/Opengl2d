#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "./VertexBuffers/VertexBuffer.h"
#include "./IndexBuffers/IndexBuffer.h"
// #include "VertexArray.h"

#include "./Shaders/ShaderInitialize.h"

template <typename T>
void Log(T value){
    std::cout << value << std::endl;
}

class Initialize
{
private:
    int windowWidth, windowHeight;

public:
    GLFWwindow *window;
    Initialize(int height, int width, const char *title);

    void Gladinitialization();
};



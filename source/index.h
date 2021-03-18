#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "./VertexBuffers/VertexBuff.h"
#include "./IndexBuffers/IndexBuffer.h"
#include "./Shaders/ShaderInitialize.h"
#include "./VertexArrays/VertexArray.h"
#include "./Renderer/Renderer.h"


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
    ~Initialize();

    void Gladinitialization();
};


#pragma once

// internal libraries and packages
#include <iostream>
#include <string>

// external libraries and packages
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "VertexBuffers/VertexBuff.h"
#include "IndexBuffers/IndexBuffer.h"
#include "Shaders/ShaderInitialize.h"
#include "VertexArrays/VertexArray.h"
#include "Renderer/Renderer.h"
#include "Texture/Texture.h"


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


#pragma once

// internal libraries and packages
#include <iostream>
#include <string>

// external libraries and packages
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VertexBuffers/VertexBuff.h"
#include "IndexBuffers/IndexBuffer.h"
#include "Shaders/ShaderInitialize.h"
#include "VertexArrays/VertexArray.h"
#include "Renderer/Renderer.h"
#include "Texture/Texture.h"
#include "ImguiHandle/ImguiHandle.h"
#include "Mvps/MvpHandle.h"
// 
#include "Camera/OrthographicCamera.h"

template <typename T>
void Log(T value)
{
    std::cout << value << std::endl;
}

class Initialize
{
private:
    int windowWidth, windowHeight;
    GLFWwindow *m_window;

public:
    Initialize(int, int, const char *);
    ~Initialize();
    GLFWwindow *getWindowReference() { return m_window; }
    void Gladinitialization();
};

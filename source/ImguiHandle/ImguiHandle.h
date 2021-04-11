#pragma once

#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

class ImguiHandle
{
private:
    /* data */
public:
    ImguiHandle(GLFWwindow *, const char *);
    void CreateNewFrame();
    void RenderElements();
    void DrawElements(float *, float *, float *, float, float, float, float);
    ~ImguiHandle();
};

#include "ImguiHandle.h"

ImguiHandle::ImguiHandle(GLFWwindow *window, const char *version)
{
    // imgui context
    ImGui::CreateContext();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(version);

    ImGui::StyleColorsDark();
}

void ImguiHandle::CreateNewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImguiHandle::RenderElements()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImguiHandle::DrawElements(float *ElementA, float *ElementB, float minA, float maxA, float minB, float maxB)
{
    {

        ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

        ImGui::SliderFloat3("Translation A", ElementA, minA, maxA);
        ImGui::SliderFloat3("Translation B", ElementB, minB, maxB);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

ImguiHandle::~ImguiHandle()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

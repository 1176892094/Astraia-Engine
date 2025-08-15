#include "ImGuiLayer.h"

#include "Application.h"
#include "imgui.h"
#include "GLFW/glfw3.h"
#include "backends/imgui_impl_glfw.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

namespace Basic
{
    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
    {
    }

    void ImGuiLayer::OnEvent(Event &event)
    {
    }

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        io.AddKeyEvent(ImGuiKey_Tab, false);
        io.AddKeyEvent(ImGuiKey_LeftArrow, false);
        io.AddKeyEvent(ImGuiKey_RightArrow, false);
        io.AddKeyEvent(ImGuiKey_UpArrow, false);
        io.AddKeyEvent(ImGuiKey_DownArrow, false);
        io.AddKeyEvent(ImGuiKey_PageUp, false);
        io.AddKeyEvent(ImGuiKey_PageDown, false);
        io.AddKeyEvent(ImGuiKey_Home, false);
        io.AddKeyEvent(ImGuiKey_End, false);
        io.AddKeyEvent(ImGuiKey_Insert, false);
        io.AddKeyEvent(ImGuiKey_Delete, false);
        io.AddKeyEvent(ImGuiKey_Backspace, false);
        io.AddKeyEvent(ImGuiKey_Space, false);
        io.AddKeyEvent(ImGuiKey_Enter, false);
        io.AddKeyEvent(ImGuiKey_Escape, false);
        io.AddKeyEvent(ImGuiKey_A, false);
        io.AddKeyEvent(ImGuiKey_C, false);
        io.AddKeyEvent(ImGuiKey_V, false);
        io.AddKeyEvent(ImGuiKey_X, false);
        io.AddKeyEvent(ImGuiKey_Y, false);
        io.AddKeyEvent(ImGuiKey_Z, false);

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());


        auto time = (float) glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnDetach()
    {
    }
}

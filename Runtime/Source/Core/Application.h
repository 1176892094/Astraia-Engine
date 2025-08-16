#pragma once
#include "Shader.h"
#include "Window.h"
#include "Source/Core/LayerStack.h"
#include "Source/Events/Event.h"
#include "Source/Events/ApplicationEvent.h"
#include "Source/GUI/ImGuiLayer.h"

namespace Engine
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

        void Run();
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;

        static Application* s_Instance;
    };

    Application *CreateApplication();
}

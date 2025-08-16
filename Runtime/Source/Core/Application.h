#pragma once
#include "Shader.h"
#include "Window.h"
#include "Source/Core/LayerStack.h"
#include "Source/Events/Event.h"
#include "Source/Events/ApplicationEvent.h"
#include "Source/GUI/ImGuiLayer.h"
#include "Source/Renderer/Buffer.h"

namespace Engine
{
    class Application
    {
    public:
        Application();

        virtual ~Application() = default;

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

        unsigned int m_VertexArray;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;

        static Application* s_Instance;
    };

    Application *CreateApplication();
}

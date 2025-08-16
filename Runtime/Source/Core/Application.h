#pragma once
#include "Shader.h"
#include "Window.h"
#include "Source/Core/LayerStack.h"
#include "Source/Events/Event.h"
#include "Source/Events/ApplicationEvent.h"
#include "Source/GUI/ImGuiLayer.h"
#include "Source/Renderer/VertexArray.h"

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

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;

        std::shared_ptr<Shader> m_BlueShader;
        std::shared_ptr<VertexArray> m_SquareVA;

        static Application* s_Instance;
    };

    Application *CreateApplication();
}

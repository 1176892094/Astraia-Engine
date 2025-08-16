#pragma once
#include "Window.h"
#include "Source/Core/LayerStack.h"
#include "Source/Events/Event.h"
#include "Source/Events/ApplicationEvent.h"

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

        void Run();
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    Application *CreateApplication();
}

#pragma once
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Basic
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run() const;

        void OnEvent(Event& e);

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}

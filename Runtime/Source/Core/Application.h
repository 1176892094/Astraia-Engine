#pragma once
#include "Window.h"
#include "Source/Events/ApplicationEvent.h"
namespace Engine
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void OnEvent(Event& e);

        void Run();
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application *CreateApplication();
}

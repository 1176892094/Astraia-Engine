#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace Basic
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run() const
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}

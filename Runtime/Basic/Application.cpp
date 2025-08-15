#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Basic
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280,720);
        AE_TRACE(e.ToString());
        while (true);
    }
}

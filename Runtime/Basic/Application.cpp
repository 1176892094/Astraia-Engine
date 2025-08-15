#include "hzpch.h"
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

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
        if (e.IsInCategory(EventCategoryApplication))
        {
            AE_TRACE(e.ToString());
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            AE_TRACE(e.ToString());
        }
        while (true);
    }
}

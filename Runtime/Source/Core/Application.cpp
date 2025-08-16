#pragma once
#include "Header.h"
#include "Application.h"
#include "Source/Events/ApplicationEvent.h"
#include "Log.h"

namespace Engine
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            HZ_TRACE(e.ToString());
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            HZ_TRACE(e.ToString());
        }

        while (true);
    }
}

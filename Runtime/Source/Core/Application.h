#pragma once

#include "Core.h"
#include "Source/Events/Event.h"

namespace Engine
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run();
    };

    Application *CreateApplication();
}

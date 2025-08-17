#pragma once
#include "Application.h"
#include "Log.h"

extern Engine::Application *Engine::CreateApplication();

int main(int argc, char **argv)
{
    Engine::Log::Init();

    HZ_PROFILE_BEGIN_SESSION("Startup", "Profile-Startup.json");
    auto app = Engine::CreateApplication();
    HZ_PROFILE_END_SESSION();

    HZ_PROFILE_BEGIN_SESSION("Runtime", "Profile-Runtime.json");
    app->Run();
    HZ_PROFILE_END_SESSION();

    HZ_PROFILE_BEGIN_SESSION("Startup", "Profile-Destroy.json");
    delete app;
    HZ_PROFILE_END_SESSION();
}

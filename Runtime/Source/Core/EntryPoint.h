#pragma once
#include "Application.h"
#include "Log.h"

extern Engine::Application *Engine::CreateApplication();

int main(int argc, char **argv)
{
    Engine::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    int a = 5;
    HZ_INFO("Hello! Var={0}", a);

    auto app = Engine::CreateApplication();
    app->Run();
    delete app;
}

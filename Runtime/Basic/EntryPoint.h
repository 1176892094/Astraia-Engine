#include "Log.h"

extern Basic::Application *CreateApplication();

int main(int argc, char **argv)
{
    Basic::Log::Init();
    AE_CORE_WARN("Initialized Log!");
    int a = 5;
    AE_INFO("Hello! Var={0}", a);
    auto app = Basic::CreateApplication();
    app->Run();
    delete app;
}

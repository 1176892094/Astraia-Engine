#include "Log.h"

extern Basic::Application *CreateApplication();

int main(int argc, char **argv)
{
    Basic::Log::Init();
    Basic::Log::GetCoreLogger()->warn("Initialized Log!");
    Basic::Log::GetClientLogger()->info("Hello!");
    auto app = Basic::CreateApplication();
    app->Run();
    delete app;
}

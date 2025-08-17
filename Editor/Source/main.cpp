#include "Engine.h"
#include "Sandbox/Sandbox2D.h"


int main(int argc, char **argv)
{
    Engine::Log::Init();
    auto app = Engine::CreateApplication();
    app->Run();
    delete app;
}

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {
    }
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}

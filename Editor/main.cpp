#include "Engine.h"
#include "Source/Core/EditorLayer.h"
#include "Source/Sandbox/Sandbox2D.h"


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
    Sandbox() : Application("Editor")
    {
        //PushLayer(new Engine::Sandbox2D());
        PushLayer(new Engine::EditorLayer());
    }

    ~Sandbox() = default;
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}

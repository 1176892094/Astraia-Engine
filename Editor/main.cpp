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

namespace Engine
{
    class Sandbox : public Application
    {
    public:
        Sandbox() : Application("Editor")
        {
            //PushLayer(new Sandbox2D());
            PushLayer(new EditorLayer());
        }

        ~Sandbox() = default;
    };

    Application *Engine::CreateApplication()
    {
        return new Sandbox();
    }
}

#include "Engine.h"
#include "Source/Core/EditorLayer.h"


int main(int argc, char **argv)
{
    Engine::Log::Init();
    auto app = Engine::CreateApplication({argc, argv});
    app->Run();
    delete app;
}

namespace Engine
{
    class Sandbox : public Application
    {
    public:
        Sandbox(ApplicationCommandLineArgs args) : Application("Astraia Engine", args)
        {
            //PushLayer(new Sandbox2D());
            PushLayer(new EditorLayer());
        }

        ~Sandbox() = default;
    };

    Application *Engine::CreateApplication(ApplicationCommandLineArgs args)
    {
        return new Sandbox(args);
    }
}

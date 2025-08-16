#include "../Basic.h"

class ExamplePlayer : public Basic::Layer
{
public:
    ExamplePlayer() : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        AE_INFO("ExamplePlayer::Update");
    }

    void OnEvent(Basic::Event &event) override
    {
        AE_TRACE("{0}", event.ToString());
    }
};

class Sandbox : public Basic::Application
{
public:
    Sandbox()
    {
      //  PushLayer(new ExamplePlayer());
        PushOverlay(new Basic::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Basic::Application *Basic::CreateApplication()
{
    return new Sandbox();
}

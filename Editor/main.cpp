#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
    ExampleLayer(): Layer("Example")
    {
    }

    void OnUpdate() override
    {
        HZ_INFO("ExampleLayer::Update");
    }

    void OnEvent(Engine::Event &event) override
    {
        HZ_TRACE("{0}", event.ToString());
    }
};

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new Engine::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}

#include "Engine.h"
#include "imgui.h"

class ExampleLayer : public Engine::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        if (Engine::Input::IsKeyPressed(258))
            HZ_TRACE("Tab key is pressed (poll)!");
    }

    void OnEvent(Engine::Event &event) override
    {
        if (event.GetEventType() == Engine::EventType::KeyPressed)
        {
            Engine::KeyPressedEvent &e = (Engine::KeyPressedEvent &) event;
            if (e.GetKeyCode() == 258)
                HZ_TRACE("Tab key is pressed (event)!");
            HZ_TRACE("{0}", (char)e.GetKeyCode());
        }
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }
};

class Sandbox : public Engine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        // PushOverlay(new Engine::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Engine::Application *Engine::CreateApplication()
{
    return new Sandbox();
}

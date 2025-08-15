#pragma once

#include "LayerStack.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Basic
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run() const;

        void OnEvent(Event &e);


        void PushLayer(Layer *layer);

        void PushOverlay(Layer *layer);

        Window &GetWindow() { return *m_Window; }

        static Application &Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application *s_Instance;
    };

    Application *CreateApplication();
}

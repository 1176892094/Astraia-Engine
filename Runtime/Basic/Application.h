#include "Core.h"
#include "Window.h"

namespace Basic
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        void Run() const;

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}

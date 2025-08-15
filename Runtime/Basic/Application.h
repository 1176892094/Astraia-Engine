#include "Core.h"

namespace Basic
{
    class ASTRAIA_API Application
    {
    public:
        Application();

        virtual ~Application();

        static void Run();
    };

    Application* CreateApplication();
}

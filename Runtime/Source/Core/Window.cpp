#include "Header.h"
#include "Window.h"
#include "Platform/MacOS/MacWindow.h"

namespace Engine
{
    Scope<Window> Window::Create(const WindowProps &props)
    {
        return CreateScope<MacWindow>(props);
    }
}

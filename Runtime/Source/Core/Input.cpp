#include "Header.h"
#include "Input.h"
#include "Platform/MacOS/MacInput.h"


namespace Engine
{
    Scope<Input> Input::s_Instance = Create();

    Scope<Input> Input::Create()
    {
        return CreateScope<MacInput>();
    }
}

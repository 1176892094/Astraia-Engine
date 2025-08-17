#include "Header.h"
#include "Source/Core/Input.h"
#include "Source/Core/Application.h"
#include <GLFW/glfw3.h>

#include "glm/vec2.hpp"

namespace Engine
{
    bool Input::IsKeyPressed(const KeyCode key)
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, key);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    auto Input::IsMouseButtonPressed(MouseCode button) -> bool
    {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    glm::vec2 Input::GetMousePosition()
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {(float) xpos, (float) ypos};
    }

    float Input::GetMouseX()
    {
        return GetMousePosition().x;
    }

    float Input::GetMouseY()
    {
        return GetMousePosition().y;
    }
}

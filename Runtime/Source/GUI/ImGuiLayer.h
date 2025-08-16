#pragma once

#include "Source/Core/Layer.h"

namespace Engine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        ~ImGuiLayer();

        void OnAttach();

        void OnDetach();

        void OnUpdate();

        void OnEvent(Event &event);

    private:
        float m_Time = 0.0f;
    };
}

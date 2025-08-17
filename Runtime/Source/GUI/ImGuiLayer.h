#pragma once

#include "Source/Core/Layer.h"

namespace Engine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}

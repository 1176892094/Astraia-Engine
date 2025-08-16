#pragma once

#include "Source/Core/Layer.h"
#include "Source/Events/ApplicationEvent.h"
#include "Source/Events/KeyEvent.h"
#include "Source/Events/MouseEvent.h"

namespace Engine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}

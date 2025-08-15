#pragma once
#include "Layer.h"

namespace Basic
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();

        ~ImGuiLayer() = default;

        void OnAttach() override;

        void OnDetach() override;

        void OnEvent(Event &e) override;

        void OnUpdate() override;

        // void Begin();
        //
        // void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

        void SetDarkThemeColors();

        uint32_t GetActiveWidgetID() const;

    private:
        float m_Time = 0.0f;
        bool m_BlockEvents = true;
    };
}

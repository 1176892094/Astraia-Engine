#pragma once

#include "Source/Core/Core.h"
#include "Source/Core/Input.h"

namespace Engine
{
    class MacInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;

        virtual float GetMouseXImpl() override;

        virtual float GetMouseYImpl() override;
    };
}

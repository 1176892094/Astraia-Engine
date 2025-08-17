#pragma once

#include "Header.h"
#include "Source/Core/Core.h"
#include "Source/Scene/Scene.h"
#include "Source/Scene/Entity.h"

namespace Engine
{
    class SceneHierarchyPanel
    {
    public:
        SceneHierarchyPanel() = default;

        SceneHierarchyPanel(const Ref<Scene> &scene);

        void SetContext(const Ref<Scene> &scene);

        void OnImGuiRender();

    private:
        void DrawEntityNode(Entity entity);

        Ref<Scene> m_Context;
        Entity m_SelectionContext;
    };
}

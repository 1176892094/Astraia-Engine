cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)
file(COPY ${CMAKE_SOURCE_DIR}/Editor/Resource DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/Editor/Assets DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB YAML_CPP_SRC Plugins/yaml/src/*.cpp)
add_library(yaml STATIC ${YAML_CPP_SRC})
target_include_directories(yaml PUBLIC Plugins/yaml/include)

file(GLOB_RECURSE CORE_CPP_SRC CONFIGURE_DEPENDS Runtime/*.cpp)

add_library(source SHARED ${CORE_CPP_SRC}
        Plugins/glad/src/glad.c
        Plugins/stb/include/stb_image.cpp

        Plugins/imgui/imgui.cpp
        Plugins/imgui/imgui_draw.cpp
        Plugins/imgui/imgui_tables.cpp
        Plugins/imgui/imgui_widgets.cpp
        Plugins/imgui/imgui_demo.cpp
        Plugins/imgui/backends/imgui_impl_glfw.cpp
        Plugins/imgui/backends/imgui_impl_opengl3.cpp
        Plugins/ImGuizmo/ImGuizmo.cpp
)

target_include_directories(source PUBLIC
        Runtime
        Plugins/glm
        Plugins/imgui
        Plugins/box2d
        Plugins/ImGuizmo
        Plugins/stb/include
        Plugins/yaml/include
        Plugins/entt/include
        Plugins/glfw/include
        Plugins/glad/include
        Plugins/spdlog/include)

target_link_libraries(source PUBLIC
        yaml
        ${CMAKE_SOURCE_DIR}/Plugins/glfw/lib-arm64/libglfw3.a
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo")

add_executable(Astraia
        Editor/main.cpp
        Editor/Source/Sandbox/ExampleLayer.cpp
        Editor/Source/Sandbox/Sandbox2D.cpp
        Editor/Source/Core/EditorLayer.cpp)

target_link_libraries(Astraia PRIVATE source)

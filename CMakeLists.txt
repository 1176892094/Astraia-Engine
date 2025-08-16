cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(source SHARED
        Runtime/Header.cpp
        Runtime/Source/Core/Application.cpp
        Runtime/Source/Core/Log.cpp
        Runtime/Source/Core/Layer.cpp
        Runtime/Source/Core/LayerStack.cpp
        Runtime/Source/GUI/ImGuiLayer.cpp
        Runtime/Platform/MacOS/MacWindow.cpp
        Runtime/Platform/MacOS/MacInput.cpp
        Runtime/Platform/OpenGL/OpenGLContext.cpp
        Runtime/Source/Core/Shader.cpp
        Runtime/Source/Renderer/Renderer.cpp
        Runtime/Source/Renderer/Buffer.cpp
        Runtime/Platform/OpenGL/OpenGLBuffer.cpp

        Plugins/glad/src/glad.c

        Plugins/imgui/imgui.cpp
        Plugins/imgui/imgui_draw.cpp
        Plugins/imgui/imgui_tables.cpp
        Plugins/imgui/imgui_widgets.cpp
        Plugins/imgui/imgui_demo.cpp
        Plugins/imgui/backends/imgui_impl_glfw.cpp
        Plugins/imgui/backends/imgui_impl_opengl3.cpp)


target_include_directories(source PUBLIC
        Runtime
        Plugins/glm
        Plugins/imgui
        Plugins/glfw/include
        Plugins/glad/include
        Plugins/spdlog/include)

target_link_libraries(source PUBLIC
        ${CMAKE_SOURCE_DIR}/Plugins/glfw/lib-arm64/libglfw3.a
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo")

add_executable(Astraia Editor/main.cpp)
target_link_libraries(Astraia PRIVATE source)

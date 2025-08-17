cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_library(source SHARED
        Runtime/Header.cpp
        Runtime/Source/Core/Application.cpp
        Runtime/Source/Core/Log.cpp
        Runtime/Source/Core/Layer.cpp
        Runtime/Source/Core/LayerStack.cpp
        Runtime/Source/Core/OrthographicCameraController.cpp
        Runtime/Source/GUI/ImGuiLayer.cpp

        Runtime/Platform/MacOS/MacWindow.cpp
        Runtime/Platform/MacOS/MacInput.cpp

        Runtime/Source/Renderer/Shader.cpp
        Runtime/Source/Renderer/Texture.cpp
        Runtime/Source/Renderer/RendererAPI.cpp
        Runtime/Source/Renderer/Renderer.cpp
        Runtime/Source/Renderer/Buffer.cpp
        Runtime/Source/Renderer/VertexArray.cpp
        Runtime/Source/Renderer/RenderCommand.cpp
        Runtime/Source/Renderer/OrthographicCamera.cpp

        Runtime/Platform/OpenGL/OpenGLShader.cpp
        Runtime/Platform/OpenGL/OpenGLTexture.cpp
        Runtime/Platform/OpenGL/OpenGLRendererAPI.cpp
        Runtime/Platform/OpenGL/OpenGLContext.cpp
        Runtime/Platform/OpenGL/OpenGLBuffer.cpp
        Runtime/Platform/OpenGL/OpenGLVertexArray.cpp

        Plugins/glad/src/glad.c
        Plugins/stb/include/stb_image.cpp

        Plugins/imgui/imgui.cpp
        Plugins/imgui/imgui_draw.cpp
        Plugins/imgui/imgui_tables.cpp
        Plugins/imgui/imgui_widgets.cpp
        Plugins/imgui/imgui_demo.cpp
        Plugins/imgui/backends/imgui_impl_glfw.cpp
        Plugins/imgui/backends/imgui_impl_opengl3.cpp
        Runtime/Source/Renderer/Renderer2D.cpp
        Runtime/Source/Renderer/Renderer2D.h
        Runtime/Source/Renderer/GraphicsContext.cpp
)

target_include_directories(source PUBLIC
        Runtime
        Plugins/glm
        Plugins/imgui
        Plugins/stb/include
        Plugins/glfw/include
        Plugins/glad/include
        Plugins/spdlog/include)

target_link_libraries(source PUBLIC
        ${CMAKE_SOURCE_DIR}/Plugins/glfw/lib-arm64/libglfw3.a
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo")

add_executable(Astraia Editor/Sandbox.cpp)
target_link_libraries(Astraia PRIVATE source)

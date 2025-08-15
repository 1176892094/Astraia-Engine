cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(Basic SHARED
        Runtime/Basic/hzpch.cpp

        Runtime/Basic/Application.cpp
        Runtime/Basic/Log.cpp

        Runtime/Basic/Layer.cpp
        Runtime/Basic/LayerStack.cpp

        Runtime/Basic/IMGUI/ImGuiLayer.cpp

        Runtime/Basic/Platform/Windows/MacWindow.cpp
        Runtime/Basic/Platform/OpenGL/ImGuiOpenGLRenderer.cpp
)

target_include_directories(Basic PUBLIC
        Runtime/Basic
        ${PROJECT_SOURCE_DIR}/ThirdParty/imgui
        ${PROJECT_SOURCE_DIR}/ThirdParty/imgui/backends
        ${PROJECT_SOURCE_DIR}/ThirdParty/spdlog/include
        ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/include
        ${PROJECT_SOURCE_DIR}/ThirdParty/glad/include)

target_sources(Basic PRIVATE ${PROJECT_SOURCE_DIR}/ThirdParty/glad/src/glad.c)

target_link_libraries(Basic PUBLIC
        ${CMAKE_SOURCE_DIR}/ThirdParty/glfw/lib-arm64/libglfw3.a  # 或 dylib
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo"
)

add_executable(Astraia Sandbox/main.cpp)
target_link_libraries(Astraia PRIVATE Basic)
cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(Basic SHARED
        Runtime/Basic/hzpch.cpp
        Runtime/Basic/hzpch.h

        Runtime/Basic/Events/ApplicationEvent.h
        Runtime/Basic/Events/Event.h
        Runtime/Basic/Events/KeyEvent.h
        Runtime/Basic/Events/MouseEvent.h

        Runtime/Basic/Application.cpp
        Runtime/Basic/Application.h
        Runtime/Basic/Core.h
        Runtime/Basic/EntryPoint.h
        Runtime/Basic/Log.cpp
        Runtime/Basic/Log.h

        Runtime/Basic/Window.h
        Runtime/Basic/Platform/Windows/MacWindow.cpp
        Runtime/Basic/Platform/Windows/MacWindow.h
        Runtime/Basic/KeyCodes.h
        Runtime/Basic/MouseCodes.h
        Runtime/Basic/Layer.cpp
        Runtime/Basic/Layer.h
        Runtime/Basic/LayerStack.cpp
        Runtime/Basic/LayerStack.h
)



target_include_directories(Basic PUBLIC Runtime/Basic)
target_include_directories(Basic PUBLIC ${PROJECT_SOURCE_DIR}/ThirdParty/spdlog/include)
target_include_directories(Basic PUBLIC ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/include)

add_executable(Astraia Sandbox/main.cpp)

target_link_libraries(Astraia PRIVATE Basic)

# 链接 GLFW 库
target_link_libraries(Basic PUBLIC
        ${CMAKE_SOURCE_DIR}/ThirdParty/glfw/lib-arm64/libglfw3.a  # 或 dylib
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo"
)
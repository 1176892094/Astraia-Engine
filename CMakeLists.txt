cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(source SHARED
        Runtime/Header.cpp
        Runtime/Platform/MacOS/MacWindow.cpp
        Runtime/Source/Core/Application.cpp
        Runtime/Source/Core/Log.cpp
        Runtime/Source/Core/Layer.cpp
        Runtime/Source/Core/LayerStack.cpp)

target_include_directories(source PUBLIC
        Runtime
        ${PROJECT_SOURCE_DIR}/Plugins/glfw/include
        ${PROJECT_SOURCE_DIR}/Plugins/spdlog/include)

target_link_libraries(source PUBLIC
        ${CMAKE_SOURCE_DIR}/Plugins/glfw/lib-arm64/libglfw3.a
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo")

add_executable(Astraia Editor/main.cpp)
target_link_libraries(Astraia PRIVATE source)

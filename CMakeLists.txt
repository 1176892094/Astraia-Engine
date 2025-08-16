cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(source SHARED Runtime/Source/Core/Application.cpp
        Runtime/Source/Core/Log.cpp
        Runtime/Source/Core/Log.h)

target_include_directories(source PUBLIC
        Runtime
        ${PROJECT_SOURCE_DIR}/Plugins/spdlog/include)

add_executable(Astraia Editor/main.cpp)
target_link_libraries(Astraia PRIVATE source)

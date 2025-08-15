cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(Basic SHARED
        Runtime/Basic/Application.cpp
        Runtime/Basic/Application.h
        Runtime/Basic/Core.h
        Runtime/Basic/EntryPoint.h
        Runtime/Basic/Log.cpp
        Runtime/Basic/Log.h)

target_include_directories(Basic PUBLIC Runtime/Basic)

add_executable(Astraia Sandbox/main.cpp)

target_link_libraries(Astraia PRIVATE Basic)
cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(Basic SHARED src/Basic/Application.cpp)

target_include_directories(Basic PUBLIC src/Basic)

add_executable(Astraia Sandbox/main.cpp
        src/Basic/EntryPoint.h)

target_link_libraries(Astraia PRIVATE Basic)
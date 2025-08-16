cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_library(source SHARED Runtime/Source/Core/Application.cpp)

target_include_directories(source PUBLIC Runtime)

add_executable(Astraia Editor/main.cpp)
target_link_libraries(Astraia PRIVATE source)

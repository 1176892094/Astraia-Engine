cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Astraia Editor/main.cpp
        Runtime/Source/Core/Application.cpp
        Runtime/Source/Core/Application.h
        Runtime/Source/Core/Core.h
        Runtime/Source/Core/EntryPoint.h
        Runtime/Astraia.h)

cmake_minimum_required(VERSION 4.0)
project(Astraia)

set(CMAKE_CXX_STANDARD 20)


add_library(Runtime SHARED Library/Test.cpp)

target_include_directories(Runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Library)

add_executable(Astraia main.cpp)

target_link_libraries(Astraia PRIVATE Runtime)
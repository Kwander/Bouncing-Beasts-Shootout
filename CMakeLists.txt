cmake_minimum_required(VERSION 3.24)

project(F24_Kevin_Wander)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)
add_subdirectory(Quad)
add_subdirectory(MyGame)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT MyGame)
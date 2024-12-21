add_executable(MyGame MyGame.cpp)

include_directories(../Quad/include)

target_link_libraries(MyGame Quad)
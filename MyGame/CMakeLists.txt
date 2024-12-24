add_executable(MyGame    
    MyGame.cpp
    BulletWound.cpp
    CatLevel.cpp
    Enemy.cpp
    GoblinLevel.cpp
    Gun.cpp
    Level.cpp
    MonsterLevel.cpp
    NumberDisplay.cpp
)

include_directories(../Quad/include)

target_link_libraries(MyGame Quad)
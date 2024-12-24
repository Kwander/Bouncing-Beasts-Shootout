#pragma once
#include "Level.h"

class CatLevel : public Level
{
public:
    CatLevel()
        : Level("Assets/cat lvl/catlvlbackground.png",
                LevelType::CAT,
                13,   // MAX_ENEMIES
                0.5f, // SPAWN_INTERVAL
                1,    // enemyHealth
                Enemy::MovementType::ERRATIC)
    {
    }
};
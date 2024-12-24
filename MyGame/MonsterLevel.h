#pragma once
#include "Level.h"

class MonsterLevel : public Level
{
public:
    MonsterLevel()
        : Level("Assets/monster lvl/monsterlvlbackground.png",
                LevelType::MONSTER,
                9,    // MAX_ENEMIES
                2.0f, // SPAWN_INTERVAL
                4,    // enemyHealth
                Enemy::MovementType::ERRATIC)
    {
    }
};
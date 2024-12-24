#pragma once
#include "Level.h"

class GoblinLevel : public Level
{
public:
    GoblinLevel()
        : Level("Assets/goblin lvl/goblinlvlbackground (1).jpg",
                LevelType::GOBLIN,
                10,   // MAX_ENEMIES
                2.0f, // SPAWN_INTERVAL
                2,    // enemyHealth
                Enemy::MovementType::NORMAL)
    {
    }
};
#pragma once
#include "Level.h"
#include "Enemy.h"
#include "NumberDisplay.h"
#include "BulletWound.h"
#include <vector>
#include <memory>

class GoblinLevel : public Level
{
public:
    GoblinLevel();
    virtual void Update() override;
    virtual void Draw() override;
    void HandleClick(const Quad::Cursor &cursor, bool canFire, int damage);
    bool IsLevelCleared() const { return levelCleared; }

private:
    Quad::Unit gameOverScreen{"Assets/goblin lvl/goblinlvlgameover.png", 0, 0};
    Quad::Unit levelClearScreen{"Assets/goblin lvl/goblinlvlclear.png", 0, 0};
    NumberDisplay numberDisplay;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<BulletWound>> bulletWounds;
    float spawnTimer{0.0f};
    static constexpr float SPAWN_INTERVAL{2.0f};
    static constexpr int MAX_ENEMIES{10};
    static constexpr int ENEMY_DAMAGE{20};
    size_t spawnedEnemies{0};
    bool levelCleared{false};
};
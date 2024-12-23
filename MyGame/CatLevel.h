#pragma once
#include "Level.h"
#include "Enemy.h"
#include "NumberDisplay.h"
#include "BulletWound.h"
#include <vector>
#include <memory>

class CatLevel : public Level
{
public:
    CatLevel();
    virtual void Update() override;
    virtual void Draw() override;
    void HandleClick(const Quad::Cursor &cursor, bool canFire, int damage);
    bool IsLevelCleared() const { return levelCleared; }

private:
    Quad::Unit gameOverScreen{"Assets/cat lvl/catlvlgameover.png", 0, 0};
    Quad::Unit levelClearScreen{"Assets/cat lvl/catlvlclear.png", 0, 0};
    NumberDisplay numberDisplay;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<BulletWound>> bulletWounds;
    float spawnTimer{0.0f};
    static constexpr float SPAWN_INTERVAL{0.5f};
    static constexpr int MAX_ENEMIES{13};
    static constexpr int ENEMY_DAMAGE{20};
    size_t spawnedEnemies{0};
    bool levelCleared{false};
};
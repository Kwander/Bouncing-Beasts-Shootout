#pragma once
#include "Quad.h"
#include "Enemy.h"
#include "NumberDisplay.h"
#include "BulletWound.h"
#include <vector>
#include <memory>
#include <string>

class Level
{
public:
    enum class LevelType
    {
        GOBLIN,
        CAT,
        MONSTER
    };

    Level(const std::string &backgroundPath, LevelType type, int maxEnemies,
          float spawnInterval, int enemyHealth, Enemy::MovementType moveType = Enemy::MovementType::NORMAL);
    virtual ~Level() = default;

    virtual void Update();
    virtual void Draw();
    virtual void HandleClick(const Quad::Cursor &cursor, bool canFire, int damage);

    int GetPlayerHealth() const { return playerHealth; }
    int GetMaxPlayerHealth() const { return maxPlayerHealth; }
    void SetPlayerHealth(int health);
    bool IsGameOver() const { return isGameOver; }
    bool IsLevelCleared() const { return levelCleared; }
    bool CanTransition() const { return screenTimer >= SCREEN_DELAY; }
    LevelType GetType() const { return levelType; }

protected:
    Quad::Unit background;
    Quad::Unit gameOverScreen;
    Quad::Unit levelClearScreen;
    NumberDisplay numberDisplay;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<BulletWound>> bulletWounds;

    int playerHealth{100};
    const int maxPlayerHealth{100};
    bool isGameOver{false};
    bool levelCleared{false};
    float screenTimer{0.0f};
    float spawnTimer{0.0f};
    size_t spawnedEnemies{0};

    LevelType levelType;
    int maxEnemies;
    float spawnInterval;
    int enemyHealth;
    Enemy::MovementType enemyMoveType;

    static constexpr float SCREEN_DELAY{2.0f};
    static constexpr int ENEMY_DAMAGE{20};
};
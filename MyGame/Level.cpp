#include "Level.h"

Level::Level(const std::string &backgroundPath, LevelType type, int maxEnemies,
             float spawnInterval, int enemyHealth, Enemy::MovementType moveType)
    : background(backgroundPath, 0, 0), levelType(type), maxEnemies(maxEnemies), spawnInterval(spawnInterval), enemyHealth(enemyHealth), enemyMoveType(moveType), gameOverScreen((type == LevelType::GOBLIN ? "Assets/goblin lvl/gameover.png" : type == LevelType::CAT ? "Assets/cat lvl/gameover.png"
                                                                                                                                                                                                                                                                        : "Assets/monster lvl/gameover.png"),
                                                                                                                                                                                 0, 0),
      levelClearScreen((type == LevelType::GOBLIN ? "Assets/goblin lvl/clear.png" : type == LevelType::CAT ? "Assets/cat lvl/clear.png"
                                                                                                           : "Assets/monster lvl/clear.png"),
                       0, 0)
{
    // No need to reassign screens here anymore
}

void Level::Update()
{
    if (IsGameOver() || levelCleared)
    {
        screenTimer += 1.0f / 60.0f;
        return;
    }

    // Check if all enemies are defeated
    bool allEnemiesDefeated = true;
    for (const auto &enemy : enemies)
    {
        if (enemy->IsActive())
        {
            allEnemiesDefeated = false;
            break;
        }
    }

    if (spawnedEnemies >= maxEnemies && allEnemiesDefeated)
    {
        levelCleared = true;
        return;
    }

    // Update enemies
    for (auto &enemy : enemies)
    {
        enemy->Update();
        if (enemy->ShouldDealDamage())
        {
            SetPlayerHealth(GetPlayerHealth() - ENEMY_DAMAGE);
        }
    }

    // Update bullet wounds
    for (auto it = bulletWounds.begin(); it != bulletWounds.end();)
    {
        (*it)->Update();
        if ((*it)->IsExpired())
        {
            it = bulletWounds.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Spawn enemies
    if (spawnedEnemies < maxEnemies)
    {
        spawnTimer += 1.0f / 60.0f;
        if (spawnTimer >= spawnInterval)
        {
            std::string enemyType;
            switch (levelType)
            {
            case LevelType::GOBLIN:
                enemyType = "goblin";
                break;
            case LevelType::CAT:
                enemyType = "cat";
                break;
            case LevelType::MONSTER:
                enemyType = "monster";
                break;
            }

            std::string imagePath = "Assets/" + enemyType + " lvl/" + enemyType + " (" + std::to_string(spawnedEnemies + 1) + ").png";
            QUAD_LOG("Spawning enemy: " << imagePath);
            enemies.push_back(std::make_unique<Enemy>(imagePath, rand() % 800, rand() % 600, enemyHealth, enemyMoveType));
            spawnTimer = 0.0f;
            spawnedEnemies++;
        }
    }
}

void Level::Draw()
{
    if (IsGameOver())
    {
        Quad::Renderer::Draw(gameOverScreen);
    }
    else if (levelCleared)
    {
        Quad::Renderer::Draw(levelClearScreen);
    }
    else
    {
        Quad::Renderer::Draw(background);
        for (auto &enemy : enemies)
        {
            enemy->Draw();
        }
        for (auto &wound : bulletWounds)
        {
            wound->Draw();
        }
        numberDisplay.DrawHealthDisplay(GetPlayerHealth(), GetMaxPlayerHealth(), 15, 15);
    }
}

void Level::HandleClick(const Quad::Cursor &cursor, bool canFire, int damage)
{
    if (!canFire)
        return;

    int x, y;
    cursor.GetPosition(x, y);

    int windowHeight = Quad::QuadWindow::GetWindow()->GetHeight();
    y = windowHeight - y;

    for (auto &enemy : enemies)
    {
        if (enemy->IsClicked(cursor))
        {
            enemy->Hit(damage);
            BulletWound::WoundType woundType = (levelType == LevelType::GOBLIN)
                                                   ? BulletWound::WoundType::GOBLIN
                                                   : BulletWound::WoundType::NORMAL;
            bulletWounds.push_back(std::make_unique<BulletWound>(x, y, woundType));
        }
    }
}

void Level::SetPlayerHealth(int health)
{
    playerHealth = (health < 0) ? 0 : health;
    if (playerHealth <= 0)
        isGameOver = true;
}
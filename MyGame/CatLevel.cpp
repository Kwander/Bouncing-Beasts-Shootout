#include "CatLevel.h"

CatLevel::CatLevel() : Level("Assets/cat lvl/catlvlbackground.png")
{
}

void CatLevel::Update()
{
    Level::Update();

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

    if (spawnedEnemies >= MAX_ENEMIES && allEnemiesDefeated)
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
    if (spawnedEnemies < MAX_ENEMIES)
    {
        spawnTimer += 1.0f / 60.0f;
        if (spawnTimer >= SPAWN_INTERVAL)
        {
            std::string imagePath = "Assets/cat lvl/cat (" + std::to_string(spawnedEnemies + 1) + ").png";
            QUAD_LOG("Spawning cat enemy: " << imagePath);
            enemies.push_back(std::make_unique<Enemy>(imagePath, rand() % 800, rand() % 600, 1, Enemy::MovementType::ERRATIC));
            spawnTimer = 0.0f;
            spawnedEnemies++;
        }
    }
}

void CatLevel::HandleClick(const Quad::Cursor &cursor, bool canFire, int damage)
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
            bulletWounds.push_back(std::make_unique<BulletWound>(x, y, BulletWound::WoundType::NORMAL));
        }
    }
}

void CatLevel::Draw()
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
        Level::Draw();
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
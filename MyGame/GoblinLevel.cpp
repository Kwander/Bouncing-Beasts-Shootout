#include "GoblinLevel.h"

GoblinLevel::GoblinLevel() : Level("Assets/goblinlvlbackground (1).jpg")
{
}

void GoblinLevel::Update()
{
    Level::Update();

    for (auto &enemy : enemies)
    {
        enemy->Update();
        if (enemy->ShouldDealDamage())
        {
            SetPlayerHealth(GetPlayerHealth() - ENEMY_DAMAGE);
        }
    }

    if (spawnedEnemies < MAX_ENEMIES)
    {
        spawnTimer += 1.0f / 60.0f;
        if (spawnTimer >= SPAWN_INTERVAL)
        {
            std::string imagePath = "Assets/goblin lvl/goblin (" + std::to_string(spawnedEnemies + 1) + ").png";
            QUAD_LOG("Spawning enemy: " << imagePath);
            enemies.push_back(std::make_unique<Enemy>(imagePath, rand() % 800, rand() % 600));
            spawnTimer = 0.0f;
            spawnedEnemies++;
        }
    }
}

void GoblinLevel::HandleClick(const Quad::Cursor &cursor)
{
    for (auto &enemy : enemies)
    {
        if (enemy->IsClicked(cursor))
        {
            enemy->SetActive(false);
        }
    }
}

void GoblinLevel::Draw()
{
    if (IsGameOver())
    {
        Quad::Renderer::Draw(gameOverScreen);
    }
    else
    {
        Level::Draw();
        for (auto &enemy : enemies)
        {
            enemy->Draw();
        }
        numberDisplay.DrawHealthDisplay(GetPlayerHealth(), GetMaxPlayerHealth(), 15, 15);
    }
}
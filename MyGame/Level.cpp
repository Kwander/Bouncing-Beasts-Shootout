#include "Level.h"
#include <string>

Level::Level(const std::string &backgroundPath) : background(backgroundPath, 0, 0)
{
}

void Level::Update()
{
}

void Level::Draw()
{
    Quad::Renderer::Draw(background);
}

void Level::SetPlayerHealth(int health)
{
    playerHealth = (health < 0) ? 0 : health;
    if (playerHealth <= 0)
        isGameOver = true;
}
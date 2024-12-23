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

GoblinLevel::GoblinLevel() : Level("Assets/goblinlvlbackground (1).jpg")
{
}

void GoblinLevel::Update()
{
    Level::Update();
}

void GoblinLevel::Draw()
{
    Level::Draw();
    DrawHealthDisplay();
}

void GoblinLevel::DrawHealthDisplay()
{
    Quad::Renderer::Draw(healthBar);
}
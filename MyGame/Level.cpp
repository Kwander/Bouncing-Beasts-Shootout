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
    if (isGameOver)
    {
        Quad::Renderer::Draw(gameOverScreen);
    }
    else
    {
        Level::Draw();
        DrawHealthDisplay();
    }
}

void GoblinLevel::DrawHealthDisplay()
{
    int x = 15;
    int y = 15;

    DrawNumber(playerHealth, x, y);

    slash.SetCoords(x + 30, y);
    Quad::Renderer::Draw(slash);

    DrawNumber(maxPlayerHealth, x + 45, y);
}

void GoblinLevel::DrawNumber(int num, int x, int y)
{
    std::string numStr = std::to_string(num);
    for (size_t i = 0; i < numStr.length(); i++)
    {
        int digit = numStr[i] - '0';
        numbers[digit].SetCoords(x + (i * 10), y);
        Quad::Renderer::Draw(numbers[digit]);
    }
}
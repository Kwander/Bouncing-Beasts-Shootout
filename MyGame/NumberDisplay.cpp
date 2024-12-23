#include "NumberDisplay.h"

NumberDisplay::NumberDisplay()
{
}

void NumberDisplay::DrawNumber(int num, int x, int y)
{
    std::string numStr = std::to_string(num);
    for (size_t i = 0; i < numStr.length(); i++)
    {
        int digit = numStr[i] - '0';
        numbers[digit].SetCoords(x + (i * 10), y);
        Quad::Renderer::Draw(numbers[digit]);
    }
}

void NumberDisplay::DrawHealthDisplay(int currentHealth, int maxHealth, int x, int y)
{
    DrawNumber(currentHealth, x, y);

    slash.SetCoords(x + 30, y);
    Quad::Renderer::Draw(slash);

    DrawNumber(maxHealth, x + 45, y);
}
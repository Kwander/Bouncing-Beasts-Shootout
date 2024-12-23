#pragma once
#include "Quad.h"

class NumberDisplay
{
public:
    NumberDisplay();
    void DrawNumber(int num, int x, int y);
    void DrawHealthDisplay(int currentHealth, int maxHealth, int x, int y);

private:
    Quad::Unit numbers[10] = {
        {"Assets/numbers/0.jpg", 0, 0},
        {"Assets/numbers/1.jpg", 0, 0},
        {"Assets/numbers/2.jpg", 0, 0},
        {"Assets/numbers/3.jpg", 0, 0},
        {"Assets/numbers/4.jpg", 0, 0},
        {"Assets/numbers/5.jpg", 0, 0},
        {"Assets/numbers/6.jpg", 0, 0},
        {"Assets/numbers/7.jpg", 0, 0},
        {"Assets/numbers/8.jpg", 0, 0},
        {"Assets/numbers/9.jpg", 0, 0}};
    Quad::Unit slash{"Assets/numbers/slash.png", 0, 0};
};
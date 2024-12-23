#pragma once
#include "Quad.h"
#include <string>

class Level
{
public:
    Level(const std::string &backgroundPath);
    virtual ~Level() = default;

    virtual void Update();
    virtual void Draw();

    int GetPlayerHealth() const { return playerHealth; }
    int GetMaxPlayerHealth() const { return maxPlayerHealth; }
    void SetPlayerHealth(int health);
    bool IsGameOver() const { return isGameOver; }

protected:
    Quad::Unit background;
    int playerHealth{100};
    const int maxPlayerHealth{100};
    bool isGameOver{false};
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
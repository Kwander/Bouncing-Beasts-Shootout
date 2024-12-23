#pragma once
#include "Quad.h"

class Level
{
public:
    Level(const std::string &backgroundPath);
    virtual ~Level() = default;

    virtual void Update();
    virtual void Draw();

    int GetPlayerHealth() const { return playerHealth; }
    int GetMaxPlayerHealth() const { return maxPlayerHealth; }
    void SetPlayerHealth(int health) { playerHealth = health; }

protected:
    Quad::Unit background;
    int playerHealth{100};
    const int maxPlayerHealth{100};
};

class GoblinLevel : public Level
{
public:
    GoblinLevel();
    virtual void Update() override;
    virtual void Draw() override;

private:
    Quad::Unit healthBar{"Assets/greenbar.png", 10, 10};
    void DrawHealthDisplay();
};
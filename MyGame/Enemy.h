#pragma once
#include "Quad.h"

class Enemy
{
public:
    Enemy(const std::string &imagePath, int startX, int startY);
    void Update();
    void Draw();
    bool IsClicked(const Quad::Cursor &cursor) const;
    bool IsActive() const { return active; }
    void SetActive(bool isActive) { active = isActive; }
    bool ShouldDealDamage();

private:
    Quad::Unit sprite;
    bool active{true};
    float animationTimer{0.0f};
    float damageTimer{0.0f};
    static constexpr float ANIMATION_INTERVAL{0.5f};
    static constexpr float DAMAGE_INTERVAL{4.0f};
    bool isFirstFrame{true};
};
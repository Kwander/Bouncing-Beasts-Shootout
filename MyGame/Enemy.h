#pragma once
#include "Quad.h"

class Enemy
{
public:
    Enemy(const std::string& imagePath, int startX, int startY, int hitsRequired = 2);
    void Update();
    void Draw();
    bool IsClicked(const Quad::Cursor& cursor) const;
    bool IsActive() const { return active; }
    void SetActive(bool isActive) { active = isActive; }
    bool ShouldDealDamage();
    void Hit(int damage);

private:
    Quad::Unit sprite;
    bool active{true};
    float animationTimer{0.0f};
    float damageTimer{0.0f};
    static constexpr float ANIMATION_INTERVAL{0.5f};
    static constexpr float DAMAGE_INTERVAL{2.5f};
    bool isFirstFrame{true};
    int hits{0};
    int hitsToKill;
};
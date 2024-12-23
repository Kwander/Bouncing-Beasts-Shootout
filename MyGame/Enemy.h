#pragma once
#include "Quad.h"

class Enemy
{
public:
    enum class MovementType
    {
        NORMAL,
        ERRATIC
    };

    Enemy(const std::string &imagePath, int startX, int startY, int hitsRequired, MovementType moveType = MovementType::NORMAL);
    void Update();
    void Draw();
    bool IsClicked(const Quad::Cursor &cursor) const;
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
    MovementType movementType;
    float velocityX{0.0f};
    float velocityY{0.0f};
    float directionTimer{0.0f};
    static constexpr float DIRECTION_CHANGE_INTERVAL{1.0f};
    float normalSpeed{4.0f};
    static constexpr float ERRATIC_SPEED{17.0f};
    int startX{0};
    static constexpr int SHUFFLE_RANGE{50};
};
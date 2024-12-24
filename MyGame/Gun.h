#pragma once
#include "Quad.h"

class Gun
{
public:
    Gun(const std::string &holdImagePath, const std::string &fireImagePath, float fireRate, int damage);
    void Draw();
    void Update();
    void TriggerFire();
    bool CanFire() const { return canFire; }
    int GetDamage() const { return damage; }

private:
    Quad::Unit holdSprite;
    Quad::Unit fireSprite;
    bool isFiring{false};
    float cooldownTimer{0.0f};
    float fireDisplayTimer{0.0f};
    static constexpr float FIRE_DISPLAY_TIME{0.4f};
    float fireRate;
    int damage;
    bool canFire{true};
};
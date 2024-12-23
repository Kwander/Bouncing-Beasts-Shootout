#pragma once
#include "Quad.h"

class BulletWound
{
public:
    enum class WoundType
    {
        GOBLIN,
        CAT
    };

    BulletWound(int x, int y, WoundType type, bool alternateImage = false);
    void Draw();
    bool IsExpired() const { return lifetime >= MAX_LIFETIME; }
    void Update();

private:
    Quad::Unit sprite;
    float lifetime{0.0f};
    static constexpr float MAX_LIFETIME{0.5f};
    static bool nextImageAlternate;
};
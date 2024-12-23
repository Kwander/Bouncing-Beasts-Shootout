#pragma once
#include "Quad.h"

class BulletWound
{
public:
    BulletWound(int x, int y, bool alternateImage = false);
    void Draw();
    bool IsExpired() const { return lifetime >= MAX_LIFETIME; }
    void Update();

private:
    Quad::Unit sprite;
    float lifetime{0.0f};
    static constexpr float MAX_LIFETIME{0.5f};
    static bool nextImageAlternate;
};
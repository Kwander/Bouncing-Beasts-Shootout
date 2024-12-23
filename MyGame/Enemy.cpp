#include "Enemy.h"

Enemy::Enemy(const std::string &imagePath, int startX, int startY)
    : sprite(imagePath, startX, startY)
{
}

void Enemy::Update()
{
    if (!active)
        return;

    animationTimer += 1.0f / 60.0f;
    if (animationTimer >= ANIMATION_INTERVAL)
    {
        isFirstFrame = !isFirstFrame;
        animationTimer = 0.0f;

        if (isFirstFrame)
            sprite.UpdateXCoord(10);
        else
            sprite.UpdateXCoord(-10);
    }

    damageTimer += 1.0f / 60.0f;
}

bool Enemy::ShouldDealDamage()
{
    if (!active || damageTimer < DAMAGE_INTERVAL)
        return false;

    damageTimer = 0.0f; 
    return true;
}

void Enemy::Draw()
{
    if (active)
    {
        Quad::Renderer::Draw(sprite);
    }
}

bool Enemy::IsClicked(const Quad::Cursor &cursor) const
{
    return active && cursor.IsClickingOn(sprite);
}
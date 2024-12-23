#include "Enemy.h"

Enemy::Enemy(const std::string &imagePath, int startX, int startY, int hitsRequired)
    : sprite(imagePath, startX, startY), hitsToKill(hitsRequired)
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

void Enemy::Hit(int damage)
{
    hits += damage;
    QUAD_LOG("Enemy hit! Current hits: " << hits);
    if (hits >= hitsToKill)
    {
        active = false;
        QUAD_LOG("Enemy died!");
    }
}
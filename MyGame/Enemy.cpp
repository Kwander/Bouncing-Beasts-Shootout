#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(const std::string &imagePath, int startX, int startY, int hitsRequired, MovementType moveType)
    : sprite(imagePath, startX, startY), hitsToKill(hitsRequired), movementType(moveType), startX(startX)
{
    // Initialize random velocities for erratic movement
    if (movementType == MovementType::ERRATIC)
    {
        velocityX = (rand() % 200 - 100) / 100.0f * ERRATIC_SPEED;
        velocityY = (rand() % 200 - 100) / 100.0f * ERRATIC_SPEED;
    }
}

void Enemy::Update()
{
    if (!active)
        return;

    animationTimer += 1.0f / 60.0f;
    damageTimer += 1.0f / 60.0f;

    if (movementType == MovementType::ERRATIC)
    {
        // Update position
        int x = sprite.GetXCoord();
        int y = sprite.GetYCoord();
        x += static_cast<int>(velocityX);
        y += static_cast<int>(velocityY);

        // Bounce off screen edges
        if (x < 0 || x > 800)
        {
            velocityX = -velocityX;
            x = std::max(0, std::min(x, 800));
        }
        if (y < 0 || y > 600)
        {
            velocityY = -velocityY;
            y = std::max(0, std::min(y, 600));
        }

        sprite.SetCoords(x, y);

        // Randomly change direction occasionally
        directionTimer += 1.0f / 60.0f;
        if (directionTimer >= DIRECTION_CHANGE_INTERVAL)
        {
            if (rand() % 3 == 0)
            { // 33% chance to change direction
                velocityX = (rand() % 200 - 100) / 100.0f * ERRATIC_SPEED;
                velocityY = (rand() % 200 - 100) / 100.0f * ERRATIC_SPEED;
            }
            directionTimer = 0.0f;
        }
    }
    else
    {
        // Shuffling movement for goblins
        int x = sprite.GetXCoord();
        x += static_cast<int>(normalSpeed);

        // Reverse direction if we've moved too far from start position
        if (x > startX + SHUFFLE_RANGE || x < startX - SHUFFLE_RANGE)
        {
            normalSpeed = -normalSpeed;
            x = std::max(startX - SHUFFLE_RANGE, std::min(x, startX + SHUFFLE_RANGE));
        }

        sprite.SetCoords(x, sprite.GetYCoord());
    }
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
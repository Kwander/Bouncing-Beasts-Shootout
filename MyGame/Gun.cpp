#include "Gun.h"

Gun::Gun(const std::string &holdImagePath, const std::string &fireImagePath, float fireRate, int damage)
    : holdSprite(holdImagePath, 400, 0), fireSprite(fireImagePath, 400, 0), fireRate(fireRate), damage(damage)
{
}

void Gun::Update()
{
    if (!canFire)
    {
        cooldownTimer += 1.0f / 60.0f;
        if (cooldownTimer >= fireRate)
        {
            canFire = true;
            cooldownTimer = 0.0f;
        }
    }

    if (isFiring)
    {
        fireDisplayTimer += 1.0f / 60.0f;
        if (fireDisplayTimer >= FIRE_DISPLAY_TIME)
        {
            isFiring = false;
            fireDisplayTimer = 0.0f;
        }
    }
}

void Gun::Draw()
{
    if (isFiring)
    {
        Quad::Renderer::Draw(fireSprite);
    }
    else
    {
        Quad::Renderer::Draw(holdSprite);
    }
}

void Gun::TriggerFire()
{
    if (canFire)
    {
        isFiring = true;
        canFire = false;
        cooldownTimer = 0.0f;
        fireDisplayTimer = 0.0f;
    }
}

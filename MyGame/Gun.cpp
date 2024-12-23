#include "Gun.h"

Gun::Gun(const std::string &holdImagePath, const std::string &fireImagePath)
    : holdSprite(holdImagePath, 400, 0),
      fireSprite(fireImagePath, 400, 0)
{
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
    isFiring = true;
}

void Gun::SetFiring(bool firing)
{
    isFiring = firing;
}
#include "BulletWound.h"

bool BulletWound::nextImageAlternate = false;

BulletWound::BulletWound(int x, int y, WoundType type)
    : sprite(
          type == WoundType::GOBLIN
              ? (nextImageAlternate ? "Assets/guns/bulletwoundgoblin2.png" : "Assets/guns/bulletwoundgoblin.png")
              : (nextImageAlternate ? "Assets/guns/bulletwound2.png" : "Assets/guns/bulletwound1.png"),
          x - (nextImageAlternate ? 50 : 38),
          y - (nextImageAlternate ? 50 : 65))
{
    nextImageAlternate = !nextImageAlternate;
}

void BulletWound::Update()
{
    lifetime += 1.0f / 60.0f;
}

void BulletWound::Draw()
{
    if (!IsExpired())
    {
        Quad::Renderer::Draw(sprite);
    }
}
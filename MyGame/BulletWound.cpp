#include "BulletWound.h"

bool BulletWound::nextImageAlternate = false;

BulletWound::BulletWound(int x, int y, WoundType type, bool alternateImage)
    : sprite(
          type == WoundType::GOBLIN
              ? (nextImageAlternate ? "Assets/bulletwoundgoblin2.png" : "Assets/bulletwoundgoblin.png")
              : (nextImageAlternate ? "Assets/bulletwound2.png" : "Assets/bulletwound1.png"),
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
#include "BulletWound.h"

bool BulletWound::nextImageAlternate = false;

BulletWound::BulletWound(int x, int y, bool alternateImage)
    : sprite(nextImageAlternate ? "Assets/bulletwoundgoblin2.png" : "Assets/bulletwoundgoblin.png",
             x - (nextImageAlternate ? 50 : 38), // Reduced x offset difference for bulletwound1
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
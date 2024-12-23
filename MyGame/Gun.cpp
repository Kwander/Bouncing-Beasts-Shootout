#include "Gun.h"

Gun::Gun(const std::string &imagePath) : gunSprite(imagePath, 400, 0) // Position at bottom center
{
}

void Gun::Draw()
{
    Quad::Renderer::Draw(gunSprite);
}
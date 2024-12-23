#pragma once
#include "Quad.h"

class Gun
{
public:
    Gun(const std::string &imagePath);
    void Draw();

private:
    Quad::Unit gunSprite;
};
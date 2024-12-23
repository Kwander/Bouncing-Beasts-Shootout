#pragma once
#include "Quad.h"

class Gun
{
public:
    Gun(const std::string &holdImagePath, const std::string &fireImagePath);
    void Draw();
    void TriggerFire();
    void SetFiring(bool firing);

private:
    Quad::Unit holdSprite;
    Quad::Unit fireSprite;
    bool isFiring{false};
};
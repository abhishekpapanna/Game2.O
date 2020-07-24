#ifndef BULLET_H
#define BULLET_H

#include "engine/olcPixelGameEngine.h"

class Bullet
{
public:
    Bullet();
    Bullet(float,float,char);
    bool move(float);
    bool removeb;
    float getblPosX();
    float getblPosY();
    void setblPos(float,float);
    ~Bullet();
    float bulletSpeed = -750.0f;
    char bulletType;

private:
    float bulletPosX;
    float bulletPosY;
    olc::Sprite * bulletSprite = nullptr;
    olc::Decal * bulletDecal = nullptr;
};

#endif // BULLET_H

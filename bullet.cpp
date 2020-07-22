#include "bullet.h"
#include "pixelgeinterface.h"
#include <iostream>

extern PixelGEinterface * Game;


Bullet::Bullet()
{

}

Bullet::Bullet(float posX, float posY, char type)
{
    if (type == 'b')
        bulletSprite = new olc::Sprite("./img/bullet.png");
    if (type == 'm')
        bulletSprite = new olc::Sprite("./img/missile.png");
    if (type == 'e')
    {
        bulletSprite = new olc::Sprite("./img/ebullet.png");
        bulletSpeed = 750.0f;
    }
    bulletDecal = new olc::Decal(bulletSprite);
    bulletPosX = posX;
    bulletPosY = posY;
}

bool Bullet::move(float Timer)
{
    if (bulletDecal != nullptr)
    {
        if (bulletPosY < 0 && bulletPosY > Game->ScreenHeight()){
            delete bulletDecal;
            bulletDecal = nullptr;
            //delete this;

            return true;
        }

        Game->DrawDecal({bulletPosX,bulletPosY}, bulletDecal,{0.7f,0.7f});

        bulletPosY += bulletSpeed * Timer;

    }

    return false;
}

Bullet::~Bullet()
{
    std::cout << "Bullet Deleted" << std::endl ;
}


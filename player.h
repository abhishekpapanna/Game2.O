#ifndef PLAYER_H
#define PLAYER_H

#include "engine/olcPixelGameEngine.h"
#include "bullet.h"
#include <list>

class Player
{
public:
    Player();
    float getplPosX();
    void setplPosX(float);
    float getplPosY();
    void setplPosY(float);
    void setplSpeed(float);
    float getplSpeed();
    float getplWidth();
    void DrawPlayer();
    void playerControl(float);

private:
    float playerPosX = 0.0f;
    float playerPosY = 0.0f;
    float playerSpeed = 500.0f;
    float playerWidth = 90.0f;
    olc::Sprite * playerSprite = nullptr;
    olc::Decal * playerDecal = nullptr;
    //Bullet * bullet = nullptr;
    //Bullet * missile = nullptr;
    //Bullet * missile2 = nullptr;

    std::list <Bullet> bullet;
    int missile = 5;
    //std::list <Bullet> missile2;
};

#endif // PLAYER_H

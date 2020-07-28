#ifndef PIXELGEINTERFACE_H
#define PIXELGEINTERFACE_H

#include "engine/olcPixelGameEngine.h"
#include "player.h"
#include "enemy.h"

class PixelGEinterface : public olc::PixelGameEngine
{
public:
    PixelGEinterface();
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool bulletCollision();
    Player * player = nullptr;
    olc::Decal* playerdecal = nullptr;
    olc::Sprite* bg = nullptr;
    olc::Decal* bgdecal = nullptr;
    std::list <Bullet> bullet;
    olc::Sprite* bulletsprite = nullptr;
    olc::Decal* bulletdecal = nullptr;
    float mbg = -600.0f;
    void spawnE(float);
    std::list <Enemy> enemy;

private:
    float playerPos = 0.0f;
    float playerWidth = 90.0f;
    float playerSpeed = 1.0f;
    float spawnTime = 0.0f;
};

#endif // PIXELGEINTERFACE_H

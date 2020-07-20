#ifndef ENEMY_H
#define ENEMY_H

#include "engine/olcPixelGameEngine.h"

class Enemy
{
public:
    Enemy();
    Enemy(float,float);
    bool move(float);
    void DrawEnemy();
    bool removee = false;
    float getEPosY();
    float enemyPosX = 0.0f;
    float enemyPosY = 0.0f;

private:
    olc::Sprite * enemySprite = nullptr;
    olc::Decal * enemyDecal = nullptr;
    //float enemyPosX = 0.0f;
    //float enemyPosY = 0.0f;
    float enemySpeed = 60.0f;
};

#endif // ENEMY_H

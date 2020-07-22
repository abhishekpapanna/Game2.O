#include "enemy.h"
#include "pixelgeinterface.h"

extern PixelGEinterface * Game;

Enemy::Enemy()
{

}

//Default enemy spawn constructor
Enemy::Enemy(float posX, float posY)
{
    enemyPosX = posX;
    enemyPosY = posY;
    enemySprite = new olc::Sprite("./img/enemy.png");
    enemyDecal = new olc::Decal(enemySprite);
}


//Same as bullet, except this will be generated(Spawned) Directly from the Game object.
bool Enemy::move(float Timer)
{
    if (enemyDecal != nullptr)
    {
        if (enemyPosY < 0){
            delete enemyDecal;
            enemyDecal = nullptr;

            return true;
        }

        Game->DrawDecal({enemyPosX,enemyPosY}, enemyDecal,{0.7f,0.7f});

        enemyPosY += enemySpeed * Timer;

    }

    return false;
}


//Draw method for the enemy, for other forms of enemy spawn
//It will only draw if enemy object has been initiated.
void Enemy::DrawEnemy()
{
    if (enemyDecal != nullptr)
        Game->DrawDecal({enemyPosX,enemyPosY}, enemyDecal,{0.7f,0.7f});
}

float Enemy::getEPosY()
{
    return enemyPosY;
}

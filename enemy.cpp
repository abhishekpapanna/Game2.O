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

        float offset = eHealth * 1.6;
        Game->DrawDecal({enemyPosX,enemyPosY}, enemyDecal,{0.7f,0.7f});
        Game->FillRectDecal({enemyPosX,enemyPosY - 10.0f},{offset,5}, olc::RED);

        //Game->DrawDecal({enemyPosX + 15.0f,enemyPosY + 30.0f}, Game->bulletdecal, {0.2f,0.2f});

        //Game->DrawDecal({enemyPosX + 33.0f,enemyPosY + 30.0f}, Game->bulletdecal, {0.2f,0.2f});

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

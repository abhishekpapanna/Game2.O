#include "engine/olcPixelGameEngine.h"
#include "pixelgeinterface.h"
#include "player.h"
#include "bullet.h"
#include <stdlib.h>


PixelGEinterface::PixelGEinterface()
{
    sAppName = "Game2.0";
}

bool PixelGEinterface::OnUserCreate()
{
    //Initializing All objects
    player = new Player();
    bg = new olc::Sprite("./img/bg2.png");
    bgdecal = new olc::Decal(bg);
    return true;
}

bool PixelGEinterface::OnUserUpdate(float fElapsedTime)
{
    //This method runs for every frame
    //Every frame is constructed fresh and drawn onto the screen

    //Update all bullets
    bulletCollision();
    bullet.remove_if([&](const Bullet&b){return b.removeb;});

    //Controlling the player
    player->playerControl(fElapsedTime);

    //Update enemies
    enemy.remove_if([&](const Enemy&e){return e.removee;});

    //Drawing the background
    Clear(olc::DARK_BLUE);
    DrawDecal({0.0f,mbg}, bgdecal);
    mbg += 50.0f * fElapsedTime;
    if (mbg > 0.0f) mbg = -600.0f;

    //Draw the player
    player->DrawPlayer();
    //spawn and draw enemies
    spawnE(fElapsedTime);
    //Draw all Bullets on the frame
    for (auto& b : bullet)
        b.removeb = b.move(fElapsedTime);

    return true;
}

bool PixelGEinterface::bulletCollision()
{
    olc::vf2d bPos;
    for(auto& b : bullet)
    {
        bPos = {b.getblPosX(),b.getblPosY()};
        if (b.bulletType != 'e'){
            for(auto& e : enemy){
                if (bPos.x > e.enemyPosX && bPos.x < (e.enemyPosX + 50.0f) && bPos.y > e.enemyPosY && bPos.y < (e.enemyPosY + 50.0f)){
                    if (b.bulletType == 'm') e.eHealth -= 100;
                    e.eHealth -= 5;
                    if (e.eHealth <= 0) e.removee = true;
                    b.removeb = true;
                }
            }
        }
        else{
            if (bPos.x > player->getplPosX() && bPos.x < (player->getplPosX() + 60.0f) && bPos.y > player->getplPosY() && bPos.y < (player->getplPosY() + 70.0f)){
                b.removeb = true;
            }
        }
    }

    return true;
}

//Spawn Enemies every Two seconds and also define enemy behavior in game
void PixelGEinterface::spawnE(float Timer)
{
    spawnTime += Timer;

    if (spawnTime >= 2.0f)
    {
        spawnTime = Timer;
        float init = (float)(10+(rand() % (ScreenWidth() - 100)));
        Enemy e(init,0.0f);
        e.enemyInitPosX = init;
        enemy.push_back(e);
    }

    for (auto &e : enemy) {
        e.removee = e.move(Timer);

        //Somewhat Smart Enemy, Enemy will fire only when the player is in front of its barrel
        if (player->getplPosX() < (e.enemyInitPosX + 23.0f) && (player->getplPosX() + 70.0f) > (e.enemyInitPosX + 23.0f))
        {
            e.fireTime += Timer;
            if (e.fireTime > 0.5f){
                Bullet b(e.enemyPosX + 23.0f,e.enemyPosY + 70.0f,'e');
                bullet.push_back(b);
                e.fireTime = Timer;
            }
        }
    }

    enemy.remove_if([&](const Enemy&e){return e.enemyPosY > ScreenHeight() || e.removee;});
}

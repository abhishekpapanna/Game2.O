#include "engine/olcPixelGameEngine.h"
#include "pixelgeinterface.h"
#include "player.h"
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
    //Every frame is a fresh frame with updated object locations

    //Drawing the background
    Clear(olc::DARK_BLUE);
    DrawDecal({0.0f,mbg}, bgdecal);
    mbg += 50.0f * fElapsedTime;
    if (mbg > 0.0f) mbg = -600.0f;

    //Update all bullets
    bullet.remove_if([&](const Bullet&b){return b.removeb;});

    //Draw the player first and then perform player actions
    player->DrawPlayer();
    spawnE(fElapsedTime);
    player->playerControl(fElapsedTime);

    //Draw all Bullets
    for (auto& b : bullet)
    {
        b.removeb = b.move(fElapsedTime);
    }

    return true;
}

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
        if (player->getplPosX() < (e.enemyInitPosX + 23.0f) && (player->getplPosX() + 70.0f) > (e.enemyInitPosX + 23.0f))       //Somewhat Smart Enemy
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


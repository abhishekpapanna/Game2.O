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

    //Draw the player first and then perform player actions
    player->DrawPlayer();
    spawnE(fElapsedTime);
    player->playerControl(fElapsedTime);

    return true;
}

void PixelGEinterface::spawnE(float Timer)
{
    spawnTime += Timer;

    if (spawnTime >= 2.0f)
    {
        spawnTime = Timer;
        Enemy e((float)(10+(rand() % (ScreenWidth() - 100))),0.0f);
        enemy.push_back(e);
    }

    for (auto &e : enemy) {
        e.removee = e.move(Timer);
    }

    enemy.remove_if([&](const Enemy&e){return e.enemyPosY > ScreenHeight() || e.removee;});
}


#include "player.h"
#include "pixelgeinterface.h"
#include "engine/olcPixelGameEngine.h"

extern PixelGEinterface * Game;

Player::Player()
{
    playerSprite = new olc::Sprite("./img/player.png");
    playerDecal = new olc::Decal(playerSprite);
    playerPosX = float(Game->ScreenWidth()/2) - 50.0f;
    playerPosY = float(Game->ScreenHeight()) - 100.0f;
}


//Methods to get Player attributes
float Player::getplPosX()
{
    return playerPosX;
}

float Player::getplPosY()
{
    return playerPosY;
}

float Player::getplSpeed()
{
    return playerSpeed;
}

float Player::getplWidth()
{
    return playerWidth;
}

//Methods for setting these variables
void Player::setplPosX(float X)
{
    playerPosX = X;
}

void Player::setplPosY(float Y)
{
    playerPosY = Y;
}

//This method is for later functionality
void Player::setplSpeed(float speed)
{
    playerSpeed = speed;
}

//This method Draws the player using player decal.
void Player::DrawPlayer()
{
    if (playerDecal != nullptr)
        Game->DrawDecal({playerPosX,playerPosY},playerDecal,{0.7f,0.7f});
}

void Player::playerControl(float Timing)
{
    //Left - Right movement using arrow keys.
    //olc namespace has key definitions for all the keys with bHeld which means when the key is held
    if (Game->GetKey(olc::Key::LEFT).bHeld) playerPosX -= playerSpeed * Timing;
    if (Game->GetKey(olc::Key::RIGHT).bHeld) playerPosX += playerSpeed * Timing;

    //Bind the player position to screen
    if (playerPosX < 11.0f) playerPosX = 11.0f;
    if (playerPosX + playerWidth > float(Game->ScreenWidth()) - 10.0f) playerPosX = float(Game->ScreenWidth()) - 10.0f - playerWidth;

    //Produce bullets
    if (Game->GetKey(olc::Key::SPACE).bPressed){
        Bullet b(playerPosX + 17.0f,playerPosY + 30.0f,'b');
        Bullet b2(playerPosX + 44.0f,playerPosY + 30.0f,'b');
        bullet.push_back(b);
        bullet.push_back(b2);
    }

    if (Game->GetKey(olc::Key::M).bPressed){
        if(missile > 0){
            Bullet m(playerPosX + 29.0f,playerPosY,'m');
            bullet.push_back(m);
        }
        missile--;
    }

    for (auto &b : bullet) {
        b.removeb = b.move(Timing);
    }

    bullet.remove_if([&](const Bullet&b){return b.removeb;});

    if (Game->GetKey(olc::Key::R).bPressed) missile = 100;
}

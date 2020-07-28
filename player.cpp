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


//These methods return Player attributes
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

//Methods for setting player position variables
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

//Main function for controlling the player
void Player::playerControl(float Timing)
{
    //olc namespace has key definitions for all the keys with bHeld which means when the key is held

    //Player Movement
    //Left - Right movement using arrow keys.
    if (Game->GetKey(olc::Key::LEFT).bHeld) playerPosX -= playerSpeed * Timing;
    if (Game->GetKey(olc::Key::RIGHT).bHeld) playerPosX += playerSpeed * Timing;
    //Bind the player position to screen
    if (playerPosX < 11.0f) playerPosX = 11.0f;
    if (playerPosX + playerWidth > float(Game->ScreenWidth()) - 10.0f) playerPosX = float(Game->ScreenWidth()) - 10.0f - playerWidth;

    //Produce bullets
    if (Game->GetKey(olc::Key::SPACE).bHeld){
        fireTime += Timing;
        if(fireTime > 0.2f){
            Bullet b(playerPosX + 17.0f,playerPosY + 30.0f,'b');
            Game->bullet.push_back(b);
            Bullet b2(playerPosX + 44.0f,playerPosY + 30.0f,'b');
            Game->bullet.push_back(b2);
            fireTime = Timing;
        }
    }

    if (Game->GetKey(olc::Key::M).bPressed){
        if(missile > 0){
            Bullet m(playerPosX + 29.0f,playerPosY,'m');
            Game->bullet.push_back(m);
        }
        missile--;
    }

    //This is a cheat, It gives the player 100 more missiles to test when Reload Key is pressed
    if (Game->GetKey(olc::Key::R).bPressed) missile = 100;
}

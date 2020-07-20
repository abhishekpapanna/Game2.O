//This was taken out of OnUserupdate and added it as a method in a object class


/* if (GetKey(olc::Key::LEFT).bHeld) playerPos -= playerSpeed;
 if (GetKey(olc::Key::RIGHT).bHeld) playerPos += playerSpeed;


 if (playerPos < 11.0f) playerPos = 11.0f;
 if (playerPos + playerWidth > float(ScreenWidth()) - 10.0f) playerPos = float(ScreenWidth()) - 10.0f - playerWidth;
 //if (playerPos + playerWidth < float(ScreenWidth()) + 10.0f) playerPos = float(ScreenWidth()) + 10.0f + playerWidth; */


//this was from player class, I have learnt about lists and using it instead of manually checking for each object
/*
    if (missile != nullptr){

        if(missile->move(Timing) == false){
            delete missile;
            missile = nullptr;
        }
    }

    if (missile2 != nullptr){

        if(missile2->move(Timing) == false){
            delete missile2;
            missile2 = nullptr;
        }
    }

    if (Game->GetKey(olc::Key::SPACE).bPressed){
        //if (bullet == nullptr){
            bullet = new Bullet(playerPosX + 43.0f,playerPosY,'b');
        //}

    }

    if (bullet != nullptr){

        if(bullet->move(Timing) == false){
            delete bullet;
            bullet = nullptr;
        }
    }*/

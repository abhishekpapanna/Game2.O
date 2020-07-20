#include "engine/olcPixelGameEngine.h"
#include "pixelgeinterface.h"

PixelGEinterface * Game = new PixelGEinterface();

int main()
{
    if (Game->Construct(640,480,2,2))
        Game->Start();
    return 0;
}

#include "tank.h"


Tank::Tank(int x, int y): Moveable(initvx, initvy, initSpeed)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}

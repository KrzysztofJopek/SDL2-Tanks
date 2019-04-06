#include "tank.h"
#include "simulation.h"


Tank::Tank(int x, int y): Moveable(initvx, initvy, initSpeed)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}

void Tank::shoot()
{
    auto tankPos = getPosition();
    g_simulation->add(new Bullet(tankPos.x, tankPos.y, velocity.getLastDirection()));
}

Bullet::Bullet(int x, int y, Direction direction): Moveable(speed, direction)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}


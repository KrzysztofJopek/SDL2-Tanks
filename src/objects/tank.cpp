#include "tank.h"
#include "simulation.h"


Tank::Tank(int x, int y): Moveable(initvx, initvy, initSpeed)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}

void Tank::collide(int damage)
{
    HP -= damage;
}

void Tank::shoot()
{
    //Check for shoot delay`
    unsigned int tick = SDL_GetTicks();
    if(tick-lastshootTick < shootDelay)
        return;
    lastshootTick = tick;

    SDL_Rect tankPos = getRect();
    g_simulation->add(
            new Bullet(tankPos.x + tankPos.w/2 - Bullet::w/2,
                tankPos.y + tankPos.h/2 - Bullet::h/2,
                velocity.getLastDirection(), this)
            );
}


Bullet::Bullet(int x, int y, Direction direction, Object* parent):
   Moveable(speed, direction)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
    damage = 1;
    this->parent = parent;
}

void Bullet::collide(int damage)
{
    HP = 0;
}

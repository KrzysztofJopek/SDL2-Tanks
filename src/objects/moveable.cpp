#include "moveable.h"

Velocity::Velocity(float x, float y, float speed):vec(x,y)
{
    this->speed = speed;
}

Velocity::Velocity(float speed, Direction direction): vec(0,0)
{
    this->speed = speed;
    move(direction);
}

void Velocity::changeSpeed(float speed)
{
    this->speed = speed;
}

void Velocity::move(Direction dir)
{
    switch(dir){
        case TOP:
            vec.y-=1;
            break;
        case DOWN:
            vec.y+=1;
            break;
        case RIGHT:
            vec.x+=1;
            break;
        case LEFT:
            vec.x-=1;
            break;
    }
    direction = dir;
}

void Velocity::unmove(Direction dir)
{
    switch(dir){
        case TOP:
            vec.y+=1;
            break;
        case DOWN:
            vec.y-=1;
            break;
        case RIGHT:
            vec.x-=1;
            break;
        case LEFT:
            vec.x+=1;
            break;
    }
}

Cords<float> Velocity::getVec()
{
    return Cords<float>(vec.x*speed, vec.y*speed);
}

Direction Velocity::getLastDirection()
{
    return direction;
}

void Moveable::update(unsigned int delta)
{
    auto vel2 = velocity.getVec();
    int x = vel2.x * delta;
    int y = vel2.y * delta;
    move(x, y);
}




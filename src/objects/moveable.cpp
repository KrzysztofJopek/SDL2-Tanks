#include "moveable.h"
#include "simulation.h"

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

void Velocity::stop(Direction dir)
{
    switch(dir){
        case TOP:
            vec.y = vec.y<0 ? 0 : vec.y;
            break;
        case DOWN:
            vec.y = vec.y>0 ? 0 : vec.y;
            break;
        case RIGHT:
            vec.x = vec.x>0 ? 0 : vec.x;
            break;
        case LEFT:
            vec.x = vec.x<0 ? 0 : vec.x;
            break;
        default:
            vec.x=0;
            vec.y=0;
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
    //check for collisions with other objects
    bool moveBack = false;
    std::vector<Object*> collisions = g_simulation->findCollision(this);
    for(auto obj: collisions){
        if(obj->getParent() == this || this->getParent() == obj)
            continue;
        moveBack = true;
        obj->collide(this->getDamage());
        this->collide(obj->getDamage());
        if(obj->getHP() <= 0)
            g_simulation->remove(obj);
    }
    //check for collision with window frame
    if(!this->isInFrame()){
        moveBack=true;
        this->collide(0);
    }

    //remove dead objects
    if(this->getHP() <= 0)
        g_simulation->remove(this);

    //move back if collided
    if(moveBack)
        move(-x,-y);
}




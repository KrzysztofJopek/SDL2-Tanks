#ifndef _TANK_H_
#define _TANK_H_

#include "global.h"
#include "moveable.h"

class Tank: public Moveable{
    inline static const std::string path = "./res/tank.png";
    inline static const float initSpeed = 0.1;
    inline static const float initvx = 0;
    inline static const float initvy = 0;
    unsigned int lastshootTick = 0;
    unsigned int shootDelay = 1000;

public:
    static const int w = 50;
    static const int h = 50;

    Tank(int x, int y);
    void shoot();
    void collide(int damage);

};

class Bullet: public Moveable{
    inline static const std::string path = "./res/bullet.png";
    inline static const float speed = 0.5;
public:
    static const int w = 20;
    static const int h = 20;

    Bullet(int x, int y, Direction dir, Object* Parent);
    void collide(int damage);

};

#endif 

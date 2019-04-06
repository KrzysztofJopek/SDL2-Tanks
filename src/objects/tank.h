#ifndef _TANK_H_
#define _TANK_H_

#include "global.h"
#include "moveable.h"

class Tank: public Moveable{
    inline static const std::string path = "./res/tank.png";
    inline static const float initSpeed = 0.1;
    inline static const float initvx = 0;
    inline static const float initvy = 0;
    static const int w = 50;
    static const int h = 50;

public:
    Tank(int x, int y);
    void shoot();

};

class Bullet: public Moveable{
    inline static const std::string path = "./res/tank.png";
    static const int w = 25;
    static const int h = 25;
    inline static const float speed = 0.5;
public:
    Bullet(int x, int y, Direction dir);

};

#endif 

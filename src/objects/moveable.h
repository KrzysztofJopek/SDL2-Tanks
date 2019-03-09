#ifndef _MOVEABLE_H_
#define _MOVEABLE_H_

#include "object.h"

enum Direction {TOP=1, DOWN, RIGHT, LEFT};

class Velocity{
    Cords<float> vec;
    float speed;

public:
    Velocity(float x, float y, float speed);
    void changeSpeed(float speed);
    void move(Direction dir);
    void unmove(Direction dir);
    Cords<float> getVec();
};

class Moveable: Object{
    Velocity velocity;

};

#endif

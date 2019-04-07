#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include "global.h"
#include "object.h"
#include <string>

class Terrain: public Object{
    inline static const std::string path = "./res/terrain.png";

public:
    static const int w = 25;
    static const int h = 25;

    Terrain(int x, int y);
    void collide(int damage);
    void update(unsigned int delta);
};

#endif

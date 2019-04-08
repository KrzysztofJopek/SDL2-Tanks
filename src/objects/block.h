#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "global.h"
#include "object.h"
#include <string>

class Block: public Object{
    inline static const std::string path = "./res/block.png";

public:
    static const int w = 40;
    static const int h = 40;

    Block(int x, int y);
    void collide(int damage);
    void update(unsigned int delta);
};

#endif

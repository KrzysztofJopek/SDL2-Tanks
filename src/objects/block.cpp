#include "block.h"

Block::Block(int x, int y)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}

void Block::collide(int damage)
{
}

void Block::update(unsigned int delta)
{
}

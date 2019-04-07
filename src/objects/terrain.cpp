#include "terrain.h"

Terrain::Terrain(int x, int y)
{
    texture.loadTexture(path);
    setPosition(x,y);
    setSize(w,h);
}

void Terrain::collide(int damage)
{
    HP -= damage;
}

void Terrain::update(unsigned int delta)
{
}

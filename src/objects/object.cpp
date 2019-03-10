#include "object.h"

void Object::setSize(int w, int h)
{
    rectangle.w = w;
    rectangle.h = h;
}

void Object::setPosition(int x, int y)
{
    rectangle.x = x;
    rectangle.y = y;
}

void Object::move(int x, int y)
{
    rectangle.x += x;
    rectangle.y += y;
}

void Object::draw()
{
    SDL_RenderCopy(g_renderer, texture.getTexture(), NULL, &rectangle);
}

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

SDL_Rect Object::getRect()
{
    return rectangle;
}

int Object::getDamage()
{
    return damage;
}

int Object::getHP()
{
    return HP;
}

Object* Object::getParent()
{
    return parent;
}

bool Object::isInFrame()
{
    SDL_Rect rect = this->getRect();
    if(rect.x < 0 || rect.y < 0 || rect.x+rect.w > WIDTH || rect.y + rect.h > HEIGHT)
        return false;
    return true;
}


void Object::draw()
{
    SDL_RenderCopy(g_renderer, texture.getTexture(), NULL, &rectangle);
}

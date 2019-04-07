#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <string>
#include "global.h"
#include "texture.h"

template <class T>
struct Cords{
   T x; 
   T y;
   Cords(T x, T y);
};

class Object{
protected:
    Texture texture;
    SDL_Rect rectangle;
    int HP=1;
    int damage=0;
    Object* parent = NULL;

public:
    virtual void update(unsigned int delta) = 0;
    virtual void collide(int damage) = 0;
    void setSize(int w, int h);
    void setPosition(int x, int y);
    void move(int x, int y);
    Texture* getTexture();
    int getDamage();
    int getHP();
    bool isInFrame();
    Object* getParent();
    SDL_Rect getRect();
    void draw();
};

#include "cords.tpp"

#endif

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

public:
    virtual void update(unsigned int delta) = 0;
    void setSize(int w, int h);
    void setPosition(int x, int y);
    void move(int x, int y);
    Cords<int> getPosition();
    void draw();
};

#include "cords.tpp"

#endif

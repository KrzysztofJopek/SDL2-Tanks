#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

template <class T>
struct Cords{
   T x; 
   T y;
   Cords(T x, T y);
};

class Object{
    SDL_Texture* texture;
    Cords<int> position;

public:
    virtual void update(unsigned int delta);
    virtual void draw();
};

#include "cords.tpp"

#endif

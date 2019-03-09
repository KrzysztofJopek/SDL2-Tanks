#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "global.h"

class Object{
    SDL_Texture* texture;

public:
    virtual void update(unsigned int delta);
    virtual void draw();
};

#endif

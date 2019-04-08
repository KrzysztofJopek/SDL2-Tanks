#ifndef _SIMULATION_H_
#define _SIMULATION_H_
#include <vector>
#include "renderer.h"
#include "object.h"
#include "global.h"

class Texture;

class Simulation{
    std::vector<Object*> objects;
    SDL_Rect background;
    SDL_Rect pane;


public:
    Simulation();
    void update(unsigned int delta);
    void add(Object* object);
    void remove(Object* object);
    std::vector<Object*> findCollision(Object* object);
};

#endif

#include "simulation.h"

Simulation::Simulation(Renderer* renderer)
{
    this->renderer = renderer;
}

void Simulation::update(unsigned int delta)
{
    SDL_RenderClear(g_renderer);
    for(Object* obj : objects){
        obj->update(delta);
        obj->draw();
    }
    SDL_RenderPresent(g_renderer);
}

void Simulation::add(Object* object)
{
    objects.push_back(object);
}

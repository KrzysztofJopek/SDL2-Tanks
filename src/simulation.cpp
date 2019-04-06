#include "simulation.h"
#include <algorithm>

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

void Simulation::remove(Object* object)
{
    objects.erase(
            std::remove(objects.begin(), objects.end(), object),
            objects.end()
            );
}

std::vector<Object*> Simulation::findCollision(Object* objA)
{
    SDL_Rect rectA = objA->getRect();
    int topA = rectA.y;
    int bottomA = rectA.y + rectA.h;
    int leftA = rectA.x;
    int rightA = rectA.x + rectA.w;

    int topB, bottomB, leftB, rightB;
    std::vector<Object*> res;

    for(Object* objB: objects){
        if(objB == objA)
            continue;

        SDL_Rect rectB = objB->getRect();
        topB = rectB.y;
        bottomB = rectB.y + rectB.h;
        leftB = rectB.x;
        rightB = rectB.x + rectB.w;

        if(bottomA < topB)
            continue;
        if(topA > bottomB)
            continue;
        if(rightA < leftB)
            continue;
        if(leftA > rightB)
            continue;

        res.push_back(objB);
    };
    return res;
}


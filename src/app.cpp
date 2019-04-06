#include "app.h"
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include "tank.h"
#include "simulation.h"


Simulation* g_simulation;
App::App()
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        ERROR("Can't init\n");

    renderer = new Renderer();

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags))
        ERROR("Can't init IMG\n");

    controls = new Controls(this);
    g_simulation = new Simulation(renderer);
}

App::~App()
{
    delete renderer;
    delete controls;
    delete g_simulation;
}

void App::run()
{
    unsigned int tick1, tick2, delta;
    tick1 = SDL_GetTicks();
    Tank* tank = new Tank(0,0);
    g_simulation->add(tank);
    controls->tank = tank;
    while(running){
        tick2 = SDL_GetTicks();
        delta = tick2 - tick1;
        tick1 = tick2;

        controls->handleEvents();
        g_simulation->update(delta);
        usleep(20000);
    }
}

void App::quit()
{
    running = false;
}

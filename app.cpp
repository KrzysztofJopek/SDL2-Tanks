#include "app.h"
#include <SDL2/SDL_image.h>


App::App()
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        ERROR("Can't init\n");

    renderer = new Renderer();

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags))
        ERROR("Can't init IMG\n");

    controls = new Controls(this);
}

App::~App()
{
    delete renderer;
    delete controls;
}

void App::run()
{
    unsigned int tick1, tick2, delta;
    tick1 = SDL_GetTicks();
    while(running){
        tick2 = SDL_GetTicks();
        delta = tick2 - tick1;
        tick1 = tick2;

        controls->handleEvents();
    }
}

void App::quit()
{
    running = false;
}

#include "controls.h"

Controls::Controls(App* app){
    this->app = app;
}

void Controls::handleEvents()
{
    while(SDL_PollEvent(&event) != 0){
        handleEvent(event);
    }
}

void Controls::handleEvent(SDL_Event& e)
{
    if(e.type == SDL_QUIT){
        app->quit();
    }
}

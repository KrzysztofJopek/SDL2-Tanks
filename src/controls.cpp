#include "controls.h"
#include "moveable.h"

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
    else if(e.type == SDL_KEYDOWN && event.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_UP:
                tank->velocity.move(TOP);
                break;
            case SDLK_DOWN:
                tank->velocity.move(DOWN);
                break;
            case SDLK_LEFT:
                tank->velocity.move(LEFT);
                break;
            case SDLK_RIGHT:
                tank->velocity.move(RIGHT);
                break;
        }
    }
    else if(e.type == SDL_KEYUP && event.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_UP:
                tank->velocity.unmove(TOP);
                break;
            case SDLK_DOWN:
                tank->velocity.unmove(DOWN);
                break;
            case SDLK_LEFT:
                tank->velocity.unmove(LEFT);
                break;
            case SDLK_RIGHT:
                tank->velocity.unmove(RIGHT);
                break;
        }
    }
}

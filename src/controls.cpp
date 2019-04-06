#include "controls.h"
#include "moveable.h"

Controls::Controls(App* app)
{
    this->app = app;
}

void Controls::handleEvents()
{
    while(SDL_PollEvent(&event)){
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
                tank->velocity.stop();
                tank->velocity.move(TOP);
                break;
            case SDLK_DOWN:
                tank->velocity.stop();
                tank->velocity.move(DOWN);
                break;
            case SDLK_LEFT:
                tank->velocity.stop();
                tank->velocity.move(LEFT);
                break;
            case SDLK_RIGHT:
                tank->velocity.stop();
                tank->velocity.move(RIGHT);
                break;
            case SDLK_SPACE:
                tank->shoot();
                break;
        }
    }
    else if(e.type == SDL_KEYUP && event.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_UP:
                tank->velocity.stop(TOP);
                break;
            case SDLK_DOWN:
                tank->velocity.stop(DOWN);
                break;
            case SDLK_LEFT:
                tank->velocity.stop(LEFT);
                break;
            case SDLK_RIGHT:
                tank->velocity.stop(RIGHT);
                break;
        }
    }
}

#include "app.h"
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include "tank.h"
#include "simulation.h"
#include "parser.h"
#include "menu.h"
#include "maker.h"


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
    g_simulation = new Simulation();

    menu = new Menu(this);
    maker = new Maker(this);
}

App::~App()
{
    delete renderer;
    delete controls;
    delete g_simulation;
    delete menu;
    delete maker;
}

void App::run()
{
    while(running){
        switch(state){
            case MENU:
                handleMenu();
                break;
            case MAKER:
                handleMaker();
                break;
            case GAME:
                handleGame();
                break;
        }
    }
}

void App::quit()
{
    running = false;
}

void App::enterMenu()
{
    state = MENU;
}

void App::enterGame()
{
    state = GAME;
}

void App::enterMaker()
{
    state = MAKER;
}

void App::handleMenu()
{
    while(state == MENU && running == true){
        menu->draw();
        menu->handleInput();
    }
}

void App::handleGame()
{
    unsigned int tick1, tick2, delta;
    tick1 = SDL_GetTicks();
    if(!gameInProgress){
        Tank* tank = new Tank(0,0);
        g_simulation->add(tank);
        controls->tank = tank;
        Parser::parse("res/lvl1.txt");
        gameInProgress = true;
    }
    while(running && state == GAME){
        tick2 = SDL_GetTicks();
        delta = tick2 - tick1;
        tick1 = tick2;

        controls->handleEvents();
        g_simulation->update(delta);
        usleep(20000);
    }
}

void App::handleMaker()
{
    while(state == MAKER && running == true){
        maker->draw();
        maker->handleInput();
        usleep(20000);
    }
}


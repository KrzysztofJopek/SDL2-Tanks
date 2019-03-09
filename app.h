#ifndef _APP_H_
#define _APP_H_
#include <SDL2/SDL.h>

#include "global.h"
#include "renderer.h"
#include "controls.h"

class Controls;

class App{
    Renderer* renderer;
    Controls* controls;

    bool running = true;
public:
    App();
    ~App();
    void run();
    void quit();

};

#endif

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "global.h"
#include <SDL2/SDL.h>

class Renderer{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

public:
    Renderer();
};

#endif

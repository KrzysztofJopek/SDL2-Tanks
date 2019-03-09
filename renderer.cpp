#include "renderer.h"

Renderer::Renderer()
{
    window = SDL_CreateWindow(
            "SDL2 Pong Game",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if(!window)
        ERROR("Can't create window\n");

    renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED);
    if(!renderer)
        ERROR("Can't create renderer\n");
}


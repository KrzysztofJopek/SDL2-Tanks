#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define ERROR(x) do{fprintf(stderr, x); exit(1);}while(0);

class Simulation;
extern SDL_Renderer* g_renderer;
extern Simulation* g_simulation;

#endif

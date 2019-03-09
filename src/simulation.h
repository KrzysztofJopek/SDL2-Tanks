#ifndef _SIMULATION_H_
#define _SIMULATION_H_
#include <vector>
#include "renderer.h"
#include "global.h"

class Simulation{
    Renderer* renderer; 

public:
    Simulation(Renderer* renderer);
    void update(unsigned int delta);
};

#endif

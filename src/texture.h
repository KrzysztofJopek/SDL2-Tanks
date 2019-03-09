#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL2/SDL_image.h>
#include <string>
#include "global.h"

class Texture{
    SDL_Texture* texture = nullptr;

public:
    ~Texture();
    void loadTexture(std::string path);
    SDL_Texture* getTexture();
};

#endif

#include "texture.h"

Texture::~Texture()
{
    if(texture)
        SDL_DestroyTexture(texture);
}

SDL_Texture* Texture::getTexture()
{
    return texture;
}

void Texture::loadTexture(std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(!surface)
        ERROR("Can't load IMG\n");

    texture = SDL_CreateTextureFromSurface(g_renderer, surface);
    if(!texture)
        ERROR("Can't create texture from surface\n");

    SDL_FreeSurface(surface);
}

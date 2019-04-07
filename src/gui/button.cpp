#include "button.h"

Button::Button(int x, int y, std::string path)
{
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    texture.loadTexture(path);
}

void Button::draw()
{
    SDL_RenderCopy(g_renderer, texture.getTexture(), NULL, &rectangle);
}

bool Button::isClicked(int x, int y)
{
    if(x>=rectangle.x && x<=rectangle.x+rectangle.w &&
            y>=rectangle.y && y<=rectangle.y+rectangle.h){
        return true;
    }
    return false;
}




#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "global.h"
#include "texture.h"
#include <string>

class Button{
private:
    Texture texture;
    SDL_Rect rectangle;

public:
    inline static const int h = 100;
    inline static const int w = 300;


    Button(int x, int y, std::string path);
    void draw();
    bool isClicked(int x, int y);
};

#endif

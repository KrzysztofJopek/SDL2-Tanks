#include "choose.h"
#include <SDL2/SDL_ttf.h>
#include <fstream>

Choose::Choose(std::string path)
{
    this->path = path;
    for(const auto & entry: std::filesystem::directory_iterator(path))
        files.push_back(entry);
    if(files.empty()){
        empty = true;
        enteringName = true;
    }
    empty = false;
    curr = files.begin();
}

void Choose::next()
{
   
    if(empty && enteringName)
        return;
    if(++curr == files.end()){
        enteringName = true;
        curr--;
    }
   
}

void Choose::prev()
{
    enteringName=false;
    if(!empty && curr != files.begin())
        curr--;
}

std::string Choose::getName()
{
    if(empty)
        return "";
    if(enteringName)
        return path+owninput;
    return curr->path();
}


std::string Choose::choose()
{
    SDL_Event ev;
    while(true){
        SDL_WaitEvent(&ev);
        if(ev.type == SDL_KEYDOWN){
            switch(ev.key.keysym.sym){
                case SDLK_UP:
                    prev();
                    break;
                case SDLK_DOWN:
                    next();
                    break;
                case SDLK_RETURN:
                    if(enteringName){
                        std::ofstream output(path+owninput);
                        output.close();
                    }
                    return getName();
                case SDLK_ESCAPE:

                case SDLK_BACKSPACE:
                    if(owninput.length() > 0)
                        owninput.pop_back();
                    break;
            }
        }
        else if(ev.type == SDL_TEXTINPUT){
            owninput+= ev.text.text;
        }
        render();
    }
}

void Choose::render()
{
    SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(g_renderer);

    SDL_Color White = {255, 255, 255};
    printf("%s\n", SDL_GetError());
    TTF_Font* Sans = TTF_OpenFont("./res/DejaVuSans.ttf", 12);
    printf("%s\n", SDL_GetError());
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, getName().c_str(), White);
    printf("%s\n", SDL_GetError());

    SDL_Texture* Message = SDL_CreateTextureFromSurface(g_renderer, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = 100;
    Message_rect.y = 0;
    Message_rect.w = WIDTH-200;
    Message_rect.h = 30;


    SDL_RenderCopy(g_renderer, Message, NULL, &Message_rect);
    SDL_RenderPresent(g_renderer);
    printf("%s\n", getName().c_str()); 
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

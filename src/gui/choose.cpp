#include "choose.h"
#include <SDL2/SDL_ttf.h>
#include <fstream>

Choose::Choose(std::string path)
{
    this->path = path;
    try{
        std::filesystem::create_directories(path);
    } catch(std::filesystem::filesystem_error err){
        //ignored
    }
    for(const auto & entry: std::filesystem::directory_iterator(path))
        files.push_back(entry);
    if(files.empty()){
        empty = true;
        enteringName = true;
    }
    else{
        empty = false;
        enteringName = false;
    }
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
    if(!empty)
        enteringName=false;
    if(!empty && curr != files.begin())
        curr--;
}

std::string Choose::getName()
{
    if(enteringName)
        return path+owninput;
    if(empty)
        return "";
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
    TTF_Font* Sans = TTF_OpenFont("./res/DejaVuSans.ttf", 12);

    SDL_Rect Message_rect;
    Message_rect.x = 200;
    Message_rect.w = WIDTH-Message_rect.x*2;
    Message_rect.h = 10*15;
    Message_rect.y = (HEIGHT-Message_rect.h)/2;

    std::string name;
    name = "In game use arrows and space\nPress ESC to go back\n";
    name += "You can create new level in maker\n";
    name += "Make sure to press enter in order to save map\n\n";
    name += "Choose level or go to last position and enter new level name\n";
    if(!enteringName)
        name += "Choose level name:\n";
    else
        name += "Create new level:\n";
    name += getName();
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended_Wrapped(Sans, name.c_str(),\
            White, Message_rect.w);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(g_renderer, surfaceMessage);



    SDL_RenderCopy(g_renderer, Message, NULL, &Message_rect);
    SDL_RenderPresent(g_renderer);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

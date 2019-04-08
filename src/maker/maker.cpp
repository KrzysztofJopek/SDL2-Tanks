#include "maker.h"
#include "object.h"
#include "app.h"
#include "tank.h"
#include "terrain.h"
#include "block.h"

Maker::Maker(App* app)
{
    background.x = 0;
    background.y = 0;
    background.w = HEIGHT;
    background.h = HEIGHT;
    pane.x = HEIGHT;
    pane.y = 0;
    pane.w = WIDTH-HEIGHT;
    pane.h = HEIGHT;

    this->app = app;

    addItem(new Terrain(0, 0), TERRAIN);
    addItem(new Block(0, 0), BLOCK);
    addItem(new Tank(0, 0), TANK);

    curr = nullptr;
}

Maker::~Maker()
{
    for(auto obj: map){
        delete obj;
    }
    for(auto obj: items){
        delete obj;
    }
    
    if(curr)
        delete curr;
}

void Maker::handleInput()
{
    SDL_Event ev;
    while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_MOUSEBUTTONDOWN)
                handleClick(ev);
            else if(ev.type == SDL_KEYDOWN){
                if(ev.key.keysym.sym == SDLK_ESCAPE)
                    app->enterMenu();
            }
            else if(ev.type == SDL_QUIT){
                app->quit();
            }
    }
    handleMove();
}

void Maker::handleClick(SDL_Event& ev)
{
    if(ev.button.button == SDL_BUTTON_LEFT)
        clickObject(ev.button.x, ev.button.y);
}

void Maker::handleMove()
{
    if(curr)
        SDL_GetMouseState(&(curr->rect.x), &(curr->rect.y));
}

bool Maker::isInRect(int x, int y, SDL_Rect rect)
{
    if(x < rect.x || y < rect.y || x > rect.x + rect.w || y > rect.y + rect.h)
        return false;
    return true;
}

bool Maker::collideOnMap(SDL_Rect rect)
{
    //check if whole object fits in game area
    if(rect.x < 0 || rect.y < 0 || rect.x+rect.w > HEIGHT || rect.y+rect.h > HEIGHT)
        return true;

    //check for collision on map
    for(auto obj: map){
        if(rect.x >= obj->rect.x+obj->rect.w ||
                rect.x+rect.w <= obj->rect.x ||
                rect.y >= obj->rect.y+obj->rect.h ||
                rect.y+rect.h <= obj->rect.y){
            continue;
        }
        return true;
    }
    return false;
}

void Maker::clickObject(int x, int y)
{
    if(isInRect(x, y, background)){
        if(!collideOnMap(curr->rect)){
            switch(curr->type){
                case TANK:
                    addToMap(new Tank(0,0), TANK, x, y);
                    break;
                case BLOCK:
                    addToMap(new Block(0,0), BLOCK, x, y);
                    break;
                case TERRAIN:
                    addToMap(new Terrain(0,0), TERRAIN, x, y);
                    break;
            }
            
        }
    }
    else if(isInRect(x, y, pane)){
        ObjectHolder* obj = findItem(x, y);
        if(obj){
            switch(obj->type){
                case TANK:
                    if(curr)
                        delete curr;
                    curr = new ObjectHolder(new Tank(0,0), TANK, {0,0,0,0});
                    break;
                case BLOCK:
                    if(curr)
                        delete curr;
                    curr = new ObjectHolder(new Block(0,0), BLOCK, {0,0,0,0});
                    break;
                case TERRAIN:
                    if(curr)
                        delete curr;
                    curr = new ObjectHolder(new Terrain(0,0), TERRAIN, {0,0,0,0});
                    break;
            }
            curr->type = obj->type;
        }
    }
}
void Maker::addItem(Object* object, ObjectType type)
{
    int size = items.size();
    int col = size / 2;
    int row = size % 2;
    int posX = pane.x + row*(WIDTH-HEIGHT)/2;
    int posY = pane.y + col*(100);
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;

    items.push_back(new ObjectHolder(object, type, rect));
}

void Maker::addToMap(Object* object, ObjectType type, int x, int y)
{
    map.push_back(new ObjectHolder(object, type, {x,y,0,0}));
}

void Maker::draw()
{
    SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(g_renderer);
    SDL_SetRenderDrawColor(g_renderer, 0x00, 0x10, 0x00, 0xff);
    SDL_RenderFillRect(g_renderer, &background);
    SDL_SetRenderDrawColor(g_renderer, 0x40, 0x20, 0x00, 0xff);
    SDL_RenderFillRect(g_renderer, &pane);

    for(auto obj: map){
        obj->render();
    }
    for(auto obj: items){
        obj->render();
    }

    if(curr && curr->type != NONE){
        curr->render();
    }

    SDL_RenderPresent(g_renderer);
}

ObjectHolder* Maker::findMap(int x, int y)
{
   for(auto obj: map){
       if(isInRect(x, y, obj->rect))
           return obj;
   } 
   return nullptr;
}

ObjectHolder* Maker::findItem(int x, int y)
{
   for(auto obj: items){
       if(isInRect(x, y, obj->rect))
           return obj;
   } 
   return nullptr;
}

ObjectHolder::ObjectHolder(Object* object, ObjectType type, SDL_Rect rect)
{
    this->object = object;
    this->type = type;
    if(object){
        this->rect = object->getRect();
    }
    this->rect.x = rect.x;
    this->rect.y = rect.y;
}

ObjectHolder::~ObjectHolder()
{
    delete object;
}

void ObjectHolder::render()
{
    SDL_RenderCopy(g_renderer, object->getTexture()->getTexture(), NULL, &rect);
}

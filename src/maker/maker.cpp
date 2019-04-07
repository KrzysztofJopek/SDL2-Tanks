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
    SDL_WaitEvent(&ev);
    if(ev.type == SDL_MOUSEMOTION)
        handleMove(ev);
    else if(ev.type == SDL_MOUSEBUTTONDOWN)
        handleClick(ev);
    else if(ev.type == SDL_KEYDOWN){
        if(ev.key.keysym.sym == SDLK_ESCAPE)
            app->enterMenu();
    }
    else if(ev.type == SDL_QUIT){
        app->quit();
    }

}

void Maker::handleClick(SDL_Event& ev)
{
    if(ev.button.button == SDL_BUTTON_LEFT)
        clickObject(ev.button.x, ev.button.y);
}

void Maker::handleMove(SDL_Event& ev)
{
    if(curr){
        curr->rect.x = ev.button.x;
        curr->rect.y = ev.button.y;
    }
}

bool Maker::isInRect(int x, int y, SDL_Rect rect)
{
    if(x < rect.x || y < rect.y || x > rect.x + rect.w || y > rect.y + rect.h)
        return false;
    return true;
}

void Maker::clickObject(int x, int y)
{
    if(isInRect(x, y, background)){
        ObjectHolder* obj = findMap(x, y);
        if(obj)
            printf("FOUND MAP\n");
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
        printf("%d, %d, %d, %d\n", curr->rect.x, curr->rect.y, curr->rect.w, curr->rect.h);
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

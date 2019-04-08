#ifndef _MAKAR_H_
#define _MAKER_H_
#include "global.h"
#include <vector>
class Object;
class App;

enum ObjectType {NONE=0, TANK, TERRAIN, BLOCK};

struct ObjectHolder{
    ObjectType type = NONE;
    Object* object;
    SDL_Rect rect;

    ObjectHolder(Object* object, ObjectType type, SDL_Rect rect);
    ~ObjectHolder();
    void render();
};

class Maker{
private:
    App* app;
    SDL_Rect background;
    SDL_Rect pane;

    std::vector<ObjectHolder*> items;
    std::vector<ObjectHolder*> map;

    ObjectHolder* curr;

    void handleMove();
    void handleClick(SDL_Event& ev);
    bool isInRect(int x, int y, SDL_Rect rect);
    bool collideOnMap(SDL_Rect rect);
    void clickObject(int x, int y);
    ObjectHolder* findMap(int x, int y);
    ObjectHolder* findItem(int x, int y);
    void setObject(ObjectHolder* obj);

    void addItem(Object* object, ObjectType type);
    void addToMap(Object* object, ObjectType type, int x, int y);
    

public:
    Maker(App* app);
    ~Maker();
    void draw();
    void handleInput();

};


#endif

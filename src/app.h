#ifndef _APP_H_
#define _APP_H_

#include "global.h"
#include "renderer.h"
#include "controls.h"
#include "menu.h"

class Controls;
enum State {MENU=0, GAME, MAKER, CLOSE};

class App{
    Renderer* renderer;
    Controls* controls;
    Menu* menu;
    State state = MENU;

    bool running = true;
    bool gameInProgress = false;
public:
    App();
    ~App();
    void run();
    void quit();

    void enterMenu();
    void enterMaker();
    void enterGame();

    void handleMenu();
    void handleMaker();
    void handleGame();
};

#endif

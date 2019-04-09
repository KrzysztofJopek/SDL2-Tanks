#ifndef _APP_H_
#define _APP_H_

#include "global.h"
#include "renderer.h"
#include "controls.h"
#include <string>

class Controls;
class Menu;
class Maker;

enum State {MENU=0, GAME, MAKER, CLOSE};

class App{
    Renderer* renderer;
    Controls* controls;
    Menu* menu;
    Maker* maker;
    State state = MENU;
    std::string gameLevel;

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

    std::string getGameLevel();
};

#endif

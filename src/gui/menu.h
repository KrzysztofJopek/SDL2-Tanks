#ifndef _MENU_H_
#define _MENU_H_
#include "global.h"
#include "button.h"
#include <vector>
class App;

class Menu{
    App* app;

    Button* play;
    Button* maker;
    Button* close;

    void createButtons();
    void deleteButtons();

public:
    Menu(App* app);
    ~Menu();
    void handleInput();
    void draw();
};

#endif

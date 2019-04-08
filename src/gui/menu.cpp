#include "menu.h"
#include "app.h"

Menu::Menu(App* app)
{
    this->app = app;
    createButtons();
}

Menu::~Menu()
{
    deleteButtons();
}

void Menu::draw()
{
    SDL_RenderClear(g_renderer);
    play->draw();
    maker->draw();
    close->draw();
    SDL_RenderPresent(g_renderer);
}

void Menu::createButtons()
{
    play = new Button(0,0, "./res/playButton.png");
    maker = new Button(0,150, "./res/makerButton.png");
    close = new Button(0,300, "./res/closeButton.png");
}

void Menu::deleteButtons()
{
    delete play;
    delete maker;
    delete close;
}

void Menu::handleInput()
{
    SDL_Event e;
    SDL_WaitEvent(&e);
    if(e.type == SDL_QUIT){
        app->quit();
    }
    else if(e.type == SDL_MOUSEBUTTONDOWN){
        if(close->isClicked(e.button.x, e.button.y)){
            app->quit();
        }
        if(play->isClicked(e.button.x, e.button.y)){
            app->enterGame();
        }
        if(maker->isClicked(e.button.x, e.button.y)){
            app->enterMaker();
        }
    }
}

#ifndef _CHOOSE_H_
#define _CHOOSE_H_

#include "global.h"
#include <filesystem>
#include <vector>
#include <string>

class Choose{
    std::vector<std::filesystem::directory_entry> files;
    std::vector<std::filesystem::directory_entry>::iterator curr;
    std::string path;
    std::string owninput = "EnterLevelName";
    bool enteringName;
    bool empty;

    void next();
    void prev();
    std::string getName();
    void render();
    void ownInput();
    
public:
    Choose(std::string path);
    std::string choose();
};

#endif

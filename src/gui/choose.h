#ifndef _CHOOSE_H_
#define _CHOOSE_H_

#include "global.h"
#include <filesystem>
#include <string>

class Choose{
    std::vector<std::filesystem::directory_entry> files;
    std::vector<std::filesystem::directory_entry>::iterator curr;
    bool empty;
    void next();
    void prev();
    std::string getName();
    void render();
    
public:
    Choose(std::string path);
    std::string choose();
};

#endif

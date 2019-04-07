#include "parser.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "global.h"
#include "simulation.h"
#include "tank.h"
#include "terrain.h"


void Parser::parse(std::string path)
{
    std::ifstream file(path);
    if(!file.is_open())
        throw std::runtime_error("Can't open file\n");

    std::string line;
    int x, y;
    while(getline(file, line)){
        std::vector<std::string> tokens;
        boost::split(tokens, line, boost::is_any_of(":"));
        try{
            x = validateInt(tokens[1]);
            y = validateInt(tokens[2]);
        }
        catch(std::runtime_error& e){
            throw;
        }

        if(tokens[0] == "tank"){
                makeTank(x,y);
        }
        else if(tokens[0] == "block"){
                makeBlock(x,y);
        }
        else if(tokens[0] == "terrain"){
                makeTerrain(x,y);
        }
        else{
                throw std::runtime_error("File is corrupted\n");
        }
    }
    file.close();
}

int Parser::validateInt(std::string word)
{
        char* fEnd;
        int x = strtoul(word.c_str(), &fEnd, 10);
        if(*fEnd != '\0'){
            throw std::runtime_error("File is corrupted\n");
        }
        return x;
}

void Parser::makeTank(int x, int y)
{
    g_simulation->add(new Tank(x, y));
}

void Parser::makeBlock(int x, int y)
{
}

void Parser::makeTerrain(int x, int y)
{
    g_simulation->add(new Terrain(x,y));
}

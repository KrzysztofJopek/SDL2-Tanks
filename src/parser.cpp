#include "parser.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <boost/algorithm/string.hpp>
#include "global.h"
#include "simulation.h"
#include "tank.h"
#include "terrain.h"
#include "block.h"
#include "maker.h"


void Parser::getFunction(ObjectType oType, int x, int y)
{
    switch(oType){
        case TANK:
            useTank(x, y);
            break;
        case BLOCK:
            useBlock(x, y);
            break;
        case TERRAIN:
            useTerrain(x, y);
            break;
    }
}

void Parser::getFunction(std::string string, int x, int y)
{
    if(string == "tank"){
        useTank(x, y);
    }
    else if(string == "block"){
        useBlock(x, y);
    }
    else if(string == "terrain"){
        useTerrain(x, y);
    }
    else{
        throw std::runtime_error("File is corrupted\n");
    }
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

//
//
//

void ReadGameParser::parse(std::string path)
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
            getFunction(tokens[0], x, y);
        }
        catch(std::runtime_error& e){
            throw;
        }

    }
    file.close();
}


void ReadGameParser::useTank(int x, int y)
{
    g_simulation->add(new Tank(x, y));
}

void ReadGameParser::useBlock(int x, int y)
{
    g_simulation->add(new Block(x, y));
}

void ReadGameParser::useTerrain(int x, int y)
{
    g_simulation->add(new Terrain(x,y));
}

//
//
//

void ReadMakerParser::parse(std::string path)
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
            getFunction(tokens[0], x, y);
        }
        catch(std::runtime_error& e){
            throw;
        }

    }
    file.close();
}


void ReadMakerParser::useTank(int x, int y)
{
    maker->addToMap(new Tank(0,0), TANK, x, y);
}

void ReadMakerParser::useBlock(int x, int y)
{
    maker->addToMap(new Block(0,0), BLOCK, x, y);
}

void ReadMakerParser::useTerrain(int x, int y)
{
    maker->addToMap(new Terrain(0,0), TERRAIN, x, y);
}

#ifndef _PARSER_H_
#define _PARSER_H_
#include <string>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
class Maker;

enum ObjectType {TANK=1, TERRAIN, BLOCK};


class Parser{
public:
    Parser(){};
    virtual void parse(std::string path) = 0;

protected:
    void getFunction(ObjectType oType, int x, int y);
    void getFunction(std::string string, int x, int y);
    int validateInt(std::string word);
    virtual void useTank(int x, int y) = 0;
    virtual void useBlock(int x, int y) = 0;
    virtual void useTerrain(int x, int y) = 0;
};

class ReadGameParser : public Parser{
    private:
        void useTank(int x, int y);
        void useBlock(int x, int y);
        void useTerrain(int x, int y);

    public:
        void parse(std::string path);
        
};

class ReadMakerParser: public Parser{
    private:
        Maker* maker;
        void useTank(int x, int y);
        void useBlock(int x, int y);
        void useTerrain(int x, int y);

    public:
        ReadMakerParser(Maker* maker): maker(maker){}
        void parse(std::string path);
        
};

class WriteMakerParser: public Parser{
    private:
        std::ofstream file;
        Maker* maker;
        void useTank(int x, int y);
        void useBlock(int x, int y);
        void useTerrain(int x, int y);

    public:
        WriteMakerParser(Maker* maker): maker(maker){}
        void parse(std::string path);
        
};

#endif

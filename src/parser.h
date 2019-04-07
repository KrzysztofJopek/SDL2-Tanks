#ifndef _PARSER_H_
#define _PARSER_H_
#include <string>

class Parser{
    private:
        Parser(){}
        static void makeTank(int x, int y);
        static void makeBlock(int x, int y);
        static void makeTerrain(int x, int y);

        static int validateInt(std::string word);
    public:
        static void parse(std::string path);
        
};

#endif

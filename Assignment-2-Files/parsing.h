#ifndef ___PARSING___H__
#define ___PARSING___H__
#include "command.h"
using namespace std;

class parsing
{
    private:
        string line;
        vector<command *> listOfCommands;
    public:
        Parsing() : line() { };
        Parsing(string line) : line(line) { };
        void runLine();
        void exit();
}

#endif
#ifndef ___PARSING___H__
#define ___PARSING___H__
#include <string>
#include <cstring>
#include <vector>
//#include "command.h"
using namespace std;

class Parsing
{
    private:
        char* line;
//        vector<command *> listOfCommands;
        vector<string> listOfConnectors;
        bool exitState;
    public:
        Parsing() : line() { };
        void setLine(char* userLine);
        void runLine();
        bool exitExists();
		void buildCommand();
};

#endif
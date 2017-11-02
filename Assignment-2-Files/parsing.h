#ifndef ___PARSING___H__
#define ___PARSING___H__

using namespace std;

class Parsing
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
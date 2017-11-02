#ifndef __COMMAND_H
#define _COMMAND_H
#include <vector>
#include <iostream>
using namespace std;


class command{

public:
 command(string commands) : commands(commands) { };
 command(string commands, vector<string> args) : commands(commands), args(args) { };
 int  executeCommand();
private:
 string commands;
 vector<string> args;


 





};
#endif

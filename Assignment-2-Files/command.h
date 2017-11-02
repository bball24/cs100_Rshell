#ifndef __COMMAND_H
#define _COMMAND_H
#include <vector>
#include <iostream>
using namespace std;


class command{

public:
 command(string commands) : commands(commands) { };
 command(string commands, string connectors): commands(commands) { };
 void executeCommand();
private:
 string commands;
 vector<string> args;


 





};
#endif
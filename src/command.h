#ifndef _COMMAND_H
#define _COMMAND_H
#include <iostream>
#include <vector>
#include <string>
#include "Base.h"

using namespace std;


class Command : public Base {
 public:
 command(string commands) : commands(commands) { };
 command(string commands, vector<string> args) : commands(commands), args(args) { };
 
 private:
 string commands;
 vector<string>args;

 public:
 bool execute();
 void executeCommand();
};





#endif

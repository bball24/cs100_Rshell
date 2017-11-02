#ifndef _COMMAND_H
#define _COMMAND_H
#include <iostream>
#include <vector>
#include <string>
#include "Base.h"

using namespace std;


class Command : public Base {
 public:
 command(string commands): commands(commands) {};
 command(string commands, string connectors): commands(commands), connectors(connectors) {};

 private:
 string commands;
 string connectors;

 public:
 bool execute();
};





#endif

#ifndef _COMMAND_H
#define _COMMAND_H


class command{
 public:
 command(string commands): commands(commands) {};
 command(string commands, string connectors): commands(commands), connectors(conncectors) {};

 private:
 string commands;
 string connectors

 public:
 void executeCommands();
};





#endif

#ifndef __COMMAND_H
#define __COMMAND_H
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;


class Command{
    
public:
    command();
    command(string c);
    void executeCommand();
    void checkConnectors();
    int flag0;
    int flag1;
    string input;
private:
    
    ;
    vector<string> connectors;
    vector<string> listofCommands;
    bool flagforExit;
    bool flagforComment;
    
};

#endif

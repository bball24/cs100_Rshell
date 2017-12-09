#ifndef ____COMMAND_H_
#define ____COMMAND_H_
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class base
{
    public:
    base () { }
    virtual int executeCommand() = 0;
};

class command : public base
{
    private:
        // Stores the name of the command
        string commandName;
        // Stores the arguments respective to the given command.
        string arguments;
    public:
        // Constructors
        command() : commandName(), arguments() { }
        command(string comm, string args) : commandName(comm), arguments(args) { }
        // Attempts to run the given command from /usr/bin
        int executeCommand();
        string getCommandName();
        char** commandForPipe();
};

class connector : public base
{
    // This uses a structure similar to what was used in the
    // composite + strategy lab.
    private:
        char connectorChar;
        base* leftCommand;
        base* rightCommand;
    public:
        int executeCommand();
        void setLeftCommand(base* cmd);
        void setRightCommand(base* cmd);
};

class pipeCmd : public base
{
    private:
        command* leftCommand;
        command* rightCommand;
    public:
        int executeCommand();
        void setLeftCommand(command* cmd);
        void setRightCommand(command* cmd);
};

class inputRedirect :: public base
{
	private:
		
	base * leftCommand;
	base * rightCommand;

	public:
		int executeCommand();
		void setLeftCommand(base * cmd);
		void setRightCommand(base * cmd);


};
class OutputRedirect :: public base
{
private:
		
	base * leftCommand;
	base * rightCommand;

	public:
		int executeCommand();
		void setLeftCommand(base * cmd);
		void setRightCommand(base * cmd);
};

class appendRedirect :: public base
{
private:
	
	base * leftCommand;
	base * rightCommand;

	public:
		int executeCommand();
		void setLeftCommand(base * cmd);
		void setRightCommand(base * cmd);
};




#endif

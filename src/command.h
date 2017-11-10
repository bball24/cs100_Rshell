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

class command
{
	private:
		// Stores the name of the command
		string commandName;
		// Stores the arguments respective to the given command.
		string arguments;
	public:
		//Constructors
		command() : commandName(), arguments() { };
		command(string comm, string args) : commandName(comm), arguments(args) { };
		// Attempts to run the given command from /usr/bin
		int executeCommand();
		string getCommandName();
};


#endif

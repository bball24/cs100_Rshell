#include "command.h"

// Attempts to run the given command from /usr/bin
int command :: executeCommand()
{
	// PID is set to 0 for the child process. PID is set to the PID of the child process, in the parent process.
	pid_t pid;
	int status;
	int execReturn = 0;
	pid = fork();
	// If we aren't in the child process or parent process there was a problem with fork().
	if (pid < 0)
	{
		cout << "Error with fork()" << endl;
		exit(-1);
	}
	// Runs the executable in the child process, so we don't overwrite the
	// parent process, and lose the ability to return to main.
	else if (pid == 0)
	{
		// Need to make a char** array to use execvp.
		// Essentially we're filling it with the command name and its arguments.
		string nameAndArgs = commandName + ' ' + arguments;
		char* stringForToken = new char [nameAndArgs.size()];
		strcpy(stringForToken, nameAndArgs.c_str());
		// Get the name of the command to store it in arg[0].
		char* j = strtok (stringForToken," ");
		// Iterator for filling arg[]
		int k = 0; // Iterator
		// Allocate the data for arg
		char** arg = new char*[commandName.length()+1]; // Allocating data
		// Fill arg[]
		while(j != NULL)
		{
			arg[k] = j;
			j = strtok(NULL, " ");
			++k;
		}
		arg[k] = NULL;
		execReturn = execvp(arg[0], arg);
		delete[] stringForToken;
		delete[] arg;
		if( execReturn < 0 )
		{
			perror( "execvp Failed" );
		}
		// Return whether the command failed or succeeded.
		exit(execReturn);
	}
	else
	{
		// Get the exit status from the child process and then return it.
		while (wait(&status) != pid);
		return status;
	}
	return -1;
}

string command::getCommandName()
{
	return commandName;
}

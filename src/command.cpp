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

char** command::commandForPipe()
{
    string nameAndArgs = commandName + ' ' + arguments;
    char* stringForToken = new char [nameAndArgs.size()];
    strcpy(stringForToken, nameAndArgs.c_str());
    char* j = strtok (stringForToken," ");
    int k = 0;
    char** arg = new char*[commandName.length()+1];
    while(j != NULL)
    {
        arg[k] = j;
        j = strtok(NULL, " ");
        ++k;
    }
    arg[k] = NULL;
    return arg;
}

int connector::executeCommand()
{
    if(connectorChar == ';')
    {
        leftCommand->executeCommand();
        return rightCommand->executeCommand();
    }
    else if (connectorChar == '&')
    {
        int left = leftCommand->executeCommand();
        if (left == 0)
        {
            return rightCommand->executeCommand();
        }
        return left;
    }
    else if (connectorChar == '|')
    {
        int left = leftCommand->executeCommand();
        if (left != 0)
        {
            return rightCommand->executeCommand();
        }
        return left;
    }
    else
    {
        perror("Invalid connector used");
        return 0;
    }
    return 0;
};

void connector::setLeftCommand(base* cmd)
{
    leftCommand = cmd;
}

void connector::setRightCommand(base *cmd)
{
    rightCommand = cmd;
}

void pipeCmd::setLeftCommand(command *cmd)
{
    leftCommand = cmd;
}

void pipeCmd::setRightCommand(command *cmd)
{
    rightCommand = cmd;
}

int pipeCmd::executeCommand()
{
    int WRITE_END = 1;
    int READ_END = 0;
    char** cmd1;
    char** cmd2;
    cmd1 = leftCommand->commandForPipe();
    cmd2 = rightCommand->commandForPipe();
    int fds[2];
    pipe(fds);
    pid_t pid = fork();
    if(pid == 0)
    {
        dup2(fds[WRITE_END], STDOUT_FILENO);
        close(fds[READ_END]);
        close(fds[WRITE_END]);
        execvp(cmd1[0], cmd1);
        exit(1);
    }
    else
    {
        pid = fork();

        if(pid == 0)
        {
            dup2(fds[READ_END], STDIN_FILENO);
            close(fds[WRITE_END]);
            close(fds[READ_END]);
            execvp(cmd2[0], cmd2);
            exit(1);
        }
        else
        {
            int status;
            close(fds[READ_END]);
            close(fds[WRITE_END]);
            waitpid(pid, &status, 0);
        }
    }
}

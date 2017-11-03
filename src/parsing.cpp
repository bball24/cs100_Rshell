#include "parsing.h"
using namespace std;

void Parsing :: setLine(char* userLine)
{
    line = userLine;
}

void Parsing::runLine()
{
	int i = 0;
	char *copy = strdup(line);
	char *connectors = ";|&";
	char *token = strtok(line, connectors);
	while (token)
	{
		char a = copy[token - line + strlen(copy)];
	}

	do
	{
		buildCommand();
	} while (i > listOfConnectors.size(), ++i);

}

bool Parsing :: exitExists()
{
	return exitState;
}

void Parsing::buildCommand()
{	
	char* token = strtok(line, " ");
	string commandName = token;
	string args;
	while (token != NULL)
	{
		token = strtok(NULL, "|&;");
		if (token != NULL)
		{
			args = token;
			break;
		}
	}
	command * newcmd = new command(commandName, args);
	listOfCommands.push_back(newcmd);
}


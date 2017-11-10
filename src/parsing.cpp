#include "parsing.h"
using namespace std;

void Parsing :: setLine(char* userLine)
{
    line = userLine;
}
// Builds the commands.
// 
void Parsing::runLine()
{
	vector<bool> prevCommands;
	// Build commands and connector vectors
	buildCmdsAndCnctrs();

	// Iterate through every command
	for (unsigned i = 0; i < listOfCommands.size(); ++i)
	{
		// If one of the commands is exit. Break out of the loop
		// and set exitstate.
		if (listOfCommands.at(i)->getCommandName() == "exit")
		{
			exitState = true;
			break;
		}
		// Is this the first command being run?
		else if (prevCommands.empty())
		{
			if (listOfCommands.at(i)->executeCommand() == 0)
			{
				prevCommands.push_back(true);
			}
			else
			{
				prevCommands.push_back(false);
			}
		}
		else
		{
			// Checks to see if the connector is the && connector
			if (listOfConnectors.at(i - 1) == '&')
			{
				// If prevCommand was successful
				// Then we run our command and push the result
				// to prevCommands
				if (prevCommands.at(i - 1))
				{
					if (listOfCommands.at(i)->executeCommand() == 0)
					{
						prevCommands.push_back(true);
					}
					else
					{
						prevCommands.push_back(false);
					}
				}
				// If the prevCommand failed, then we treat
				// this command as failing too
				else
				{
					prevCommands.push_back(false);
				}
			}
			// Check to see if the connector is the || connector
			else if (listOfConnectors.at(i - 1) == '|')
			{
				// Checks to see if previous command failed
				if (!prevCommands.at(i - 1))
				{
					// If it did we execute our command and push the result back
					// onto prevCommands
					if (listOfCommands.at(i)->executeCommand() == 0)
					{
						prevCommands.push_back(true);
					}
					else
					{
						prevCommands.push_back(false);
					}
				}
				else
				{
					prevCommands.push_back(false);
				}
			}
			// If the connector is ;
			// Then simply run the command no matter what and
			// push the result back
			else if (listOfConnectors.at(i - 1) == ';')
			{
				if (listOfCommands.at(i)->executeCommand() == 0)
				{
					prevCommands.push_back(true);
				}
				else
				{
					prevCommands.push_back(false);
				}
			}
		}
	}
}

bool Parsing :: exitExists()
{
	return exitState;
}

void Parsing::buildCmdsAndCnctrs()
{
	// We need to store the delimiters
	string cnctrsToConvert = ";&|";
	const char spaceToConvert = ' ';
	// These will be used to fill vectors
	string commandName;
	string args;
	char a;
	string commandAndArgs;
	char *commandAndArgsCstr;
	// This vector stores commandAnArgs values
	vector<char*> tokenizedCommands;
	// Initializing token
	char* token = 0;
	// Making the delimiters usable by strtok()
	const char* connectors = cnctrsToConvert.c_str();
	const char* space = &spaceToConvert;
	// Create a copy of the line so that we can reference it
	// to find the delimiter used.
	char* copyOfLine = strdup(line);
	// Tokenize and store the commands + arguments into tokenizedCommands
	// Store any connectors found
	// If a comment is found we remove everything after # from the command
	// Then we break out of the loop as we won't need to store any other commands
	do
	{
		if (token != NULL)
		{
			token = strtok(NULL, connectors);
			if (token == NULL)
			{
				a = '\0';
				break;
			}
		}
		else
		{
			token = strtok(line, connectors);
		}
		commandAndArgs = token;
		size_t commentPos = commandAndArgs.find('#');
		if (commentPos != string::npos)
		{
			while (commandAndArgs.size() != commentPos)
			{
				commandAndArgs = commandAndArgs.erase(commandAndArgs.size() - 1);
			}
			if (commandAndArgs.at(commandAndArgs.size() - 1) == ' ')
			{
				commandAndArgs = commandAndArgs.erase(commandAndArgs.size() - 1);
			}
			a = copyOfLine[token - line + strlen(token)];
			commandAndArgsCstr = new char[commandAndArgs.length() + 1];
			strcpy(commandAndArgsCstr, commandAndArgs.c_str());
			tokenizedCommands.push_back(commandAndArgsCstr);
			listOfConnectors.push_back(a);
			break;
		}
		a = copyOfLine[token - line + strlen(token)];
		commandAndArgsCstr = new char[commandAndArgs.length() + 1];
		strcpy(commandAndArgsCstr, commandAndArgs.c_str());
		tokenizedCommands.push_back(commandAndArgsCstr);
		listOfConnectors.push_back(a);
	} while (token);
	
	// Separate the commandName and arguments for use in command.
	// Store the command objects.
	for (unsigned i = 0; i < tokenizedCommands.size(); ++i)
	{
		token = strtok(tokenizedCommands.at(i), space);
		commandName = token;
		token = strtok(NULL, connectors);
		if (token != NULL)
		{
			args = token;
		}
		else
		{
			args = "";
		}
		command* commandToPush = new command(commandName, args);
		listOfCommands.push_back(commandToPush);
	}
}

void Parsing::clearVectors()
{
	// we use delete for listOfCommands because we allocate data using pointers
	if (listOfCommands.size() != 0)
	{
		for (unsigned i = 0; i > listOfCommands.size(); ++i)
		{
			delete listOfCommands.at(i);
		}
	}
	listOfCommands.clear();
	listOfConnectors.clear();
}

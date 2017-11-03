#include "parsing.h"
//#include "command.h"
#include <iostream>
using namespace std;

int main()
{
    string userInput;
    Parsing userLineStorage;
	char *userLineForParsing;
    while(userLineStorage.exitExists() != true)
    {
        cout << "$ ";
        getline(cin, userInput);
		userLineForParsing = new char[userInput.size() + 1];
		strcpy(userLineForParsing, userInput.c_str());
		userLineStorage.setLine(userLineForParsing);
		userLineStorage.runLine();
    }


    return 0;
}
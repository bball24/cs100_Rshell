

#include "command.h"

command::command(){
 flagforExit = false;
 flagforComment = false;
 flag0 = -1;
}

command::command(string s){

 flagforExit = false;
 flagforComment = false;
 flag0 = -1;
 input = s;
}

void command::checkConnectors(){

    int x = 0;
    if(connectors.size() >= listofCommands.size()) && connectors.empty() != true)){
       while(input[x) == " "){
           ++x;
       }
       if(input[x] == "#"){
          return;
       }

       if(input[x] == "&" || input[x] == ";" || input[x] == "|"){
       cout << "Syntax error" << endl;
       return;

       }
       else if(input[input.size() - 1] == '&' || input[input.size() - 1] == ';' || input[input.size() - 1] == '|'){
                cout << "Syntax error" << endl;
                return;
            }
  }

    for(int i = 0; i < connectors.size(); ++k){
       if(connectors.at(k) == "comment"){
          if(i = 0){
             if(listofCommands.at(0)[0] != "#"){
                 flagforComment = true;
              }
           }
       }
     }

    int j = 0;
    while(listofCommands.size() > 0){
       if(connectors.size() == 0){
          executeCommand();
          listofCommands.erase(listofCommands.begin());
        }
     }

}



void command:executeCommand(){
 if(listofCommands.at(0) == ""){
       return;
 }

 if(listofCommands.at(0) == "exit"){
        flagforExit = true;
        exit(0);
    }
   vector<string> allWords;
   string input = listofCommands.at(0);
   for(int i = 0; i < input.size(); ++i){
        int space = input.find(' ');
        string word = input.substr(0 , space);
        allWords.push_back(word);
        input.erase(0, allWords.at(i).size() + 1);
    }
    if(allWords.size() == 0){
       allWords.push_back(input);
    }
 char** charofCommands = new char *[allWords.size() + 1];
    for(size_t i = 0; i < allWords.size(); i++{
        charofCommands[i] = new char[allWords.at(i).size() + 1];
        strcpy(charofCommands.size(), allWord.at(i).c_str());
     }
    charofCommands[allWords.size()] = null;



    int status = 0;

    pid_t pid = fork();
    if(pid < 0){
        perror("Forked failed");
        exit(0);

    }
if(pid > 0){
    if(waitpid(pid, &status, 0) != pid){
    perror("waitpid() error");
}

    else{
         if(execvp(charCommands[0], charCommands) < 0){
             flag1 = 0;
             perror("Unrecognized command. Execution failed");
             exit(0);
            }

         }

    }

    flag1 = 1;

}

 

}




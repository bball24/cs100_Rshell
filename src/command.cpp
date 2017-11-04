

#include "command.h"

Command::Command(){
 flagforExit = false;
 flagforComment = false;
 flag0 = -1;
}

Command::Command(string s){

 flagforExit = false;
 flagforComment = false;
 flag0 = -1;
 input = s;
}

void Command::checkConnectors(){

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
    else if(flagforComment == true){
          executeCommand();
          listofCommands.erase(listofCommands.begin());
          return;
     }
     else if(connectors.empty() != true){
          if(connectors.at(j) == "AND"){
             if(flag0 == -1){
                 executeCommand();
                 connectors.erase(connectors.begin());
                 listofCommands.erase(listofCommands.being()); 
           
                 if(listofCommands.empty() != true && flag1 == 1){
		     executeCommand();  
                     listofCommands.erase(listofCommands.begin());
                  }

              }
                 else if(flag1 == 1){
                      executeCommand();
                      connectors.erase(connectors.begin());
                      listofCommands.erase(userCommands.begin());
                 }
                 else{
                     connectors.erase(connectors.begin());
                     listofCommands.erase(listofCommands.begin());
                     flag1 = 0;
                 }
                ++flag0;   
          }
      else if(connectors.at(j) == "OR"){
          if(flag0 == -1){ 
               executeCommand();
               connectors.erase(connectors.begin());
               listofCommands.erase(listofCommands.begin());
              
               if(listofCommands.empty() != true && flag1 == 0){
                     executeCommand();
                     userCommands.erase(userCommands.begin());
                }
                       
                else if(listofCommands.empty() != true){
                     listofCommands.erase(listofCommands.begin());
                     flag1 = 0;
                 }
           }
           else if(flag1 == 0){
                executeCommand();
                connectors.erase(connectors.begin());
                listofCommands.erase(listofCommands.begin());

            }
            else{
                connectors.erase(connectors.begin());
                listofCommands.erase(listofCommands.begin());
                flag1 = 0;
            }
            ++flag0;       
      }              
      else if(connectors.at(j) == "SEMICOLON"){
          if(flag0 == -1){
                executeCommand();
                connectors.erase(connectors.begin());
                listofCommands.erase(listofCommands.begin());
                if(listofCommands.empty() != true){
                    executeCommand();
                    listofCommands.erase(listofCommands.begin());
                    
                 }
           }
          else{
               executeCommand();
               connectors.erase(connectors.begin());
               listofCommands.erase(listofCommands.begin());
           }
           ++flag0;
      }
      else{
      
          while(listofCommands.empty() != true){
               liestofCommands.pop_back();
           }
      }
      ++flag0; 
        
  }

}
}



void Command::executeCommand(){
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
         if(execvp(charofCommands[0], charofCommands) < 0){
             flag1 = 0;
             perror("Unrecognized command. Execution failed");
             exit(0);
            }

         }

    }

    flag1 = 1;

}

 

}




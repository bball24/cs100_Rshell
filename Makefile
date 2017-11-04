
FLAGS = -Wall -Werror -ansi -pedantic
COMP = g++

all: 
	mkdir -p ./bin
	$(COMP) $(FLAGS) ./src/command.cpp -o .bin/rshell
rshell:
	$(COMP) $(FLAGS) ./src/command.cpp -o ./bin/rshell


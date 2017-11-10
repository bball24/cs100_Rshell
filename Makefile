CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic

all: rshell
rshell:
	mkdir -p ./bin
	$(CC) $(CC_FLAGS) src/main.cpp src/command.cpp src/parsing.cpp -o bin/rshell

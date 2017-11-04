#!/bin/bash


./bin/rshell << 'EOF'

ls -a && exit

exit

mkdir newfile || exit

echo "No" || exit



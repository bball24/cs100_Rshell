
#!/bin/sh

.rshell/bin << 'EOF'

echo "Hi" || mkdir folder
ls -a || touch new.cpp

echo "Hello" || echo "Hi" || echo "exit"


touch file.cpp && echo "Hello" || ls -a



EOF

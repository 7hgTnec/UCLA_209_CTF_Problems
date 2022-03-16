#!/bin/sh

python3 ./generator.py

if [ ! -d "problems" ]; then
  mkdir problems
fi

gcc -m32 -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -ggdb -O0 -fno-stack-protector -z execstack problem1.c -o problems/problem1
gcc -m32 -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -ggdb -O0 -fno-stack-protector -z execstack problem2.c -o problems/problem2
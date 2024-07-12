#!/usr/bin/env bash

flex ch1-05.l
bison -d ch1-05.y
gcc -c -g lex.yy.c ch1-05.tab.c
gcc -o ch1-05 lex.yy.o ch1-05.tab.o -lfl

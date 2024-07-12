#!/usr/bin/env bash

flex ch1-06.l
bison -d ch1-06.y
gcc -c -g lex.yy.c ch1-06.tab.c
gcc -o ch1-06 lex.yy.o ch1-06.tab.o -lfl

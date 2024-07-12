#!/usr/bin/env bash

# flex -o ch1-01.l.c ch1-01.l
# gcc -o ch1-01 ch1-01.l.c -lfl
flex ch1-01.l
gcc -o ch1-01 lex.yy.c -lfl

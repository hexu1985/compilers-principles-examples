#!/usr/bin/env bash

flex -o ch1-03.l.c ch1-03.l
gcc -o ch1-03 ch1-03.l.c -lfl

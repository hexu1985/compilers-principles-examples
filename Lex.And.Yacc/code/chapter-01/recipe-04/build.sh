#!/usr/bin/env bash

flex -o ch1-04.l.c ch1-04.l
gcc -o ch1-04 ch1-04.l.c -lfl

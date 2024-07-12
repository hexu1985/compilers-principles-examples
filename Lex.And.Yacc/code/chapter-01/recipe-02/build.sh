#!/usr/bin/env bash

flex -o ch1-02.l.c ch1-02.l
gcc -o ch1-02 ch1-02.l.c -lfl

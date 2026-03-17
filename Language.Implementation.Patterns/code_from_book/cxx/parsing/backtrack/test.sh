#!/usr/bin/bash

./Test "[a, b]"

./Test "[a, ]"

./Test "[a, b"

./Test "[a,b=c,[d,e]]"

./Test "[a,b=c,,[d,e]]"

#!/bin/bash
cpp-10 prog.c -o prog_cpp.c
gcc-10 -c -Wall prog_cpp.c -o prog_cpp.o
gcc-10 prog_cpp.o -o prog.exe -lm 
#oppure in un colpo solo: gcc -Wall prog.c -o prog.exe

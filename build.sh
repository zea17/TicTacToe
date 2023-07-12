#!/bin/bash

g++ -c source/main.cpp -o bin/main.o
g++ -c source/setup.cpp -o bin/setup.o

g++ bin/main.o bin/setup.o -o bin/ttt

clear
./bin/ttt
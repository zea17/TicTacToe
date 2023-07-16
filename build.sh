#!/bin/bash

g++ -c source/main.cpp -o bin/main.o
g++ -c source/setup.cpp -o bin/setup.o
g++ -c source/storage_manager.cpp -o bin/storage_manager.o

g++ bin/main.o bin/setup.o bin/storage_manager.o -o bin/ttt

clear
./bin/ttt
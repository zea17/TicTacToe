#!/bin/bash

# Create bin directory if it doesn't exist
rm -rf bin
mkdir -p bin

for file in source/*.cpp; do
    filename=$(basename "$file")
    object_file="bin/${filename%.*}.o"
    g++ -c "$file" -o "$object_file"
done


# Link the object files and create the binary at bin/app
g++ -static bin/*.o -o ./bin/ttt

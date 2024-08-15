#!/bin/bash

# Check if at least one argument is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 file1.cpp [file2.cpp ...]"
    exit 1
fi

# Compile the provided .cpp files
g++ -o program "$@"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the program
    ./program
else
    echo "Compilation failed."
fi
#!/bin/bash

# Quick manual checks in single-argument format
# Usage example: ./rpn "5 5 +"

cd /home/muhsin/Desktop/Cpp-Modules/CPP09/ex01 || exit 1

echo "=== BUILD ==="
make -s clean && make -s

echo "\n=== VALID ==="
./rpn "5 5 +"
./rpn "5 5 * 6 + 7 -"
./rpn "1 2 + 3 4 + *"
./rpn "9 3 / 2 * 1 +"

echo "\n=== INVALID ==="
./rpn "5 +"
./rpn "5 5"
./rpn "5 a +"
./rpn "5 0 /"
./rpn "10 2 +"
./rpn ""
./rpn "   "

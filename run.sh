#!/bin/bash

DIR=$(cd $(dirname $0); pwd)
cd $DIR

g++ -Wall -std=c++14 -c src/main.cpp -o bin/main.o -I. -Isrc
g++ -Wall -std=c++14 -c src/rpn.cpp -o bin/rpn.o -I. -Isrc
g++ bin/main.o bin/rpn.o -o bin/main

bin/main

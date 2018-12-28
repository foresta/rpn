#!/bin/bash

DIR=$(cd $(dirname $0); pwd)
cd $DIR

g++ -Wall -std=c++14 src/main.cpp -o bin/main -I. -Isrc 

bin/main

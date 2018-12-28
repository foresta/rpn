#!/bin/bash

DIR=$(cd $(dirname $0); pwd)
cd $DIR

g++ -std=c++14 test/*.cpp -o bin/test -I. -Isrc -Igoogletest/include -Lgoogletest -lgtest -lgtest_main -lpthread

bin/test

rm bin/test

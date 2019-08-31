#!/bin/bash
SRC=$1
EXT="${SRC##*/}"
BASE="${fname_ext%.*}"
MAIN="${SRC##*.}"
DIR="${SRC%/*}"
EXE="${SRC%.*}.out"
g++ $SRC -std=c++14 -o $EXE

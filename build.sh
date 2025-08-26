#!/usr/bin/env bash

# copy the default configuration
[ -f "config.h" ] || cp -v config.def.h config.h
gcc -o game -lraylib -Wall -Wextra *.c || exit 1

#!/bin/bash

echo "Enter a valid directory"
read directory
ls -Rl directory | grep "^-" | wc -l
ls -Rl directory | grep "^d" | wc -l

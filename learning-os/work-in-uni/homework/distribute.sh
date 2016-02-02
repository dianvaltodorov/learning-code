#!/bin/bash

files=$(ls $1)
for i in $files; do
            extension="${i##*.}"
            if [ "$extension" != "$i" ]; then
              mkdir -p "$extension"
              mv "$1/$i" "$extension"
            fi
        done

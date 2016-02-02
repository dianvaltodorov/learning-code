#!/bin/bash

max=$1

shift 1

for i in $*
do
    if [ $max -le $i ]
    then
        max=$i
    fi
done

echo "Max is: $max"

#!/bin/bash
if [ $# -lt 1 ]
then
    echo "Wrong number of arguments"
fi

max=$1
for i in $*
do
    if [ $max -lt $i ]
    then
        max=$i
    fi
done

echo "Maximum is $max"

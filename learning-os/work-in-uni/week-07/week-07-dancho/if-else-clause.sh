#!/bin/bash
if [ $# -ne 2 ]
then
    echo "Wrong num of args"
    exit 99
fi

echo $1
echo $2

if [ $1 -gt $2 ]
then
    echo "Max of $1 and $2 is: $1"
fi

if [ $1 -le $2 ]
then
    echo "Max of $1 and $2 is: $2"
fi

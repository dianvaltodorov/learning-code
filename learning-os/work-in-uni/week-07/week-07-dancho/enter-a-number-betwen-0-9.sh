#!/bin/bash
echo "Enter a digit in the interval 0 and 9"
read x


until [ $x -le 9 $x -ge 0 ] 2> /dev/null
do
    echo "Enter a digit in the interval 0 and 9"
    read x
done

echo $x

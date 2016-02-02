#!/bin/bash

echo "Please enter the name of a valid name:"
read name
echo $name
who | grep $name | wc -l

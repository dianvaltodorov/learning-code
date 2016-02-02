#!/bin/bash
argcount=$1

if [[ $# -eq 0 ]];
then
  echo 'Error, no arguments given'
  exit 1
fi

shift 1
if [[ $# -ne $argcount ]];
 then echo 'Error, not enough arguments'
 exit 2
fi

res=0
for i in $@;do
   res=$(($res+$i))
done
   echo $res

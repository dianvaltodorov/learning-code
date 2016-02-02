#!/bin/bash

LOD_DIR=/var/log
ROOT_UID=0
LINES=50
E_XCD=86
E_NOTROOT=87

if [ "$UID" -ne $ROOT_UID ]
then
	echo "Must be root to run this script"
	exit $E_NOTROOT
fi

if [ -n "$1" ]
then
	lines=$1
else
	lines=$LINES
fi

cd $LOG_DIR

if [`pwd` != "$LOG_DOR" ]
then
	echo "Can't change to $LOG_DIR"
	exit $E_XCD
fi

tail -n $LINES messages > mesg.temp
mv mesg.temp messages

cat /dev/null > wtmp
echo "Log files cleaned up"

exit 0

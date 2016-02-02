#!/bin/
cp /etc/passwd .
cut -f 3 -d ':'  passwd | sort -n | uniq -c| tail -n 5

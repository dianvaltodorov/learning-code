#!/bin/bash
#Задача 1:
#Направете копие на файла /etc/passwd във вашата home директория под името my_passwd.
#Сортирайте файла числово по трето поле, спрямо разделител ":"

cp  /etc/passwd my_passwd
sort -t':' -k3 my_passwd

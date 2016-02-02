#!/bin/bash
#Задача 5:
#Направете копие на файла /etc/passwd във вашата home директория под името my_passwd.
#Сортирайте файла числово по трето поле, спрямо разделител ":"
cp /etc/passwd my_passwd
sort -k3 -t':' my_passwd

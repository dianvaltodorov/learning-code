#!/bin/bash
#Задача 1:
#Копирайте файловете f1,f2,f3 от директорията /tmp/os2015/exer02/ в директория
#dir1, намираща се във вашата home директория. Ако нямате такава, създайте я.

mkdir ~/dir1
cp /tmp/os2015/exer/f1 ~/dir1
cp /tmp/os2015/exer/f3 ~/dir1
cp /tmp/os2015/exer/f2 ~/dir1

cp /tmp/os2015/exer/f[1-3] ~/dir1

cp /tmp/os2015/exer/f* ~/dir1

cp /tmp/os2015/exer/{f1,f2,f3} ~/dir1

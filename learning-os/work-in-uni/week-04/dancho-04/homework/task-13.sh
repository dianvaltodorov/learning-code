#!/bin/bash
# Задача 3: Изведете всички редове от файла myFile02, които съдържат низа
# "user". Запазете изхода във файл "grepped". Използвайте филтър, за да
# преброите редовете от файла "grepped"
grep "user" mypasswd > grepped
wc -l grepped

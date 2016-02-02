#!/bin/bash
#Задача 3:
#Уверете се, че съдържанието на файла numbers се състои само от числа
cat ../data/data-task-03.txt | grep [0-9] | wc -m
cat ../data/data-task-03.txt | wc -m

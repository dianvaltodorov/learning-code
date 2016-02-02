#!/bin/bash
# 1. Запаметете във файл в своята home директория резултатът от командата
# ls -l изпълнена за вашата home директорията.
ls -l ~ > ~/home-content.txt
sort -t" " -k2 home-content.txt

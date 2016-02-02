Review:

Commands
---
* passwd - change password
* cd - change directory
* pwd - print working directory
* df - report disk space usage per filesystem, what filesystem are mounted
* du - disk usage
* chown - променя собственика на даден файл,
* newgrp - първо проверява дали има такава root потребителя може да казва към всяка група
* id -ch
* ll - показва и permissions и други служебни данни
* ls - показва файловете, изключва dot файловете
* permissions  drwxr-xr-x , three groups of bits (1 - owner), (2 - group), (3 - everybody else). Имаме уеб сървър и някаква директория, където са файловете. /var/www/html ivan:users 750Не може да бъде достъпен, ще покаже forbidden
* chown - change owner (`chown ivan asd.txt` - сменя owner-a на файла)
* chmod - сменя правата на достъп (u/g/a) (+/-) (r/w/x)
```
g+r asdf.txt
a+r adsf.txt
o+r adsf.txt  
```
* uid, suid, sgid
* ps -прави списък на процесите (ps -ef | grep top)
 * Всяка команда работи от името на някой потребител. Dко на някоя директория се сложи стики бит, въпреки разрешенията само този който си е създал директорията може да си променя дерикторията. При файловете вече не се ползват стики битове.
```
mkdir allAccess
chmod 777 allAccess
chmod +t allAccess
```
* mkdir - създава директория
* touch - създава празен файл. Всеки файл има creation time, modification time, access time
* UMASK 0002 - другите потребители, които не са собственици на файла не могат да пишат по него. промя на маска UMASK и новата страниц
* mkdir - създава папка
```
/tmp/1/2/3 - иска всичко по пътя да бъде вече създадени
mkdir -p
mkdir -m 777 -p /tmp/1/2/3/4
```
* ls - списък със съдържанието
ls -la /tmp/1/2/3/4/ - виждаме съдържанието на директорията.
три варианта да видим разрешенията на директоията

ls -dla /tmp/1/2/3/4 - показва

* rmdir - трие празни директории
* cp - copies files and directory
* rm - трие
```
rm -r - три рекурсивно
rm -f - не питай трий
rm -rf - трие
```
--------------------
Filesystems:
---
blocks - местата, където са записани нещата във блока
inodes - градивния елемент, което обяснява кое къде е. Съдържа метадата
  - permission
  - access, mod, creation
  - owner
  - size
  - blocks  

Ако искаме да изтрием файл, за който имам write разрешение и ако нямаме разрешение да трием от нея няма да стане. Eдин директен блок . адресируемо място от диска 512байт
Един файл ще изхаби 1 iNode и два

* df - информация за файловата система
```
df -i колко inode има празни
df - колко блока има празни
```
освен файлове и дериктори има и линкове
има два линкове - хард и софт(symlink)
Има iNode D1
File1 56
FIle2 78
File3 34
File12 34
-------------------------
Links
---
И двата файла сочат към същия node
Номерата на iNode са уникални.
Hardlink:
- Не може да се създава hardlink към файлове от други файлови системи
- Не може да се създават hardlink към несъществуващи директории
- Не може да се прави ref към директории
- hardlink не харчат дисково пространство

самия symlink е файл в който е записан името на файл.
- Може да минава през различни файлови системи.
- Може да правим реферънс към несъществуващи файлове, защото е просто едно string-че.
- Заемат място

hardlink ln
symlink ln -s

ls -li
един iNode има поле което указва колко референции има в дадента
Кога се ползват symlink? - в общия случай трябва да се стремим към тях
Кога се ползват hardlink? - почти никога няма да правим. Обикновено в ситуация в която трябва да пазим място. Ще ползваме  hardlink, за да не копира;

-------------------------
Extension нямат значение и самата операционна система не се съобразява какво е.

-------------------------
Показване на текстови файл
* cat
* more
* less
* head
* tail
 -  tail -f - ще чете след края на файл. Периодично ще се опитва да чете от файл, ако някой добавя. Удобво е за логове. Удобно е за дебъгване, когато трябва да следим някакви неща.
-------------------------
Има и binary файлове
* reset
* ctrl + j
* xxd - hex offset in the file and the byte address
* wc -l
* find - търсене на файлове
  find /usr -name chroot
  find /us
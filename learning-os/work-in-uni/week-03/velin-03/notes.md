tar - няма компресия, съдържанието на файловете се сглобява в един голям файл. Имат разширение .tar. Това разширение само себе си нищо не значи, удобство за потребителя.

```
c - create
x - extract
t - list content
f - file
v - verbose
```

```
tar cdf /tmp/asdf.tar
tar tf /tmp/asdf/tar

```

tar запазва всички метаданни, за разлика от останилите
.tar файловете се наричат tarball

Освен tar архиви има и .cpio файловете. Основната разликата е че на cpio трябва да дадем пълен списък на файловете, коиото искаме да архивираме. Има два режима
* -i input mode
* -o output mode

----
Компресия
* gzip
  - popular replacement for compress
  - example ```  gzip asdf.tar ```
  - добавя разширение .gzip
  - след успешно компресиране изтрива оригинала
  - за разархивиране  gunzip
  - zcat - команда на cat в комплект с gzip,
  - стар
  - tar cdvfz
* bzip2
  - по добро, новия формат, който се ползва по подразбиране
  - tar cvfj
* xz utils
  - по добре от bzip2
  - raf cvfJ

Традиционно файловете от интернет идват като tarball, който е компресиран.
--------------------------

Всяка програма има станадартен вход(клавиатура), стандартен изход(терминала), стандартен изход за грешка(терминала).

File I/O redirection allows redirection of STDIN, STDOUT, STDERR

proc-  не руут потребителите не могат да четат.

каквото запишем в dev/null изчезва, всичко записано в него просто го няма.

ls -laR /proc >  a.txt

p < file.txt  redirect standarde input
p > redirect standard output
p 2> file.txt redirect

`ls -R /proc/ > output`

Първо е винаги командата, която я изпълнява. По-голямото е като фуния

`ls -alR /proc/ > 1.txt 2> 2.txt`
С тази команда STDOUT отива в 1.txt, а STDERR  отива в 2.txt отива във

```
< redirects STDIN from a file
> redirects STDOUT form a file (overwrite))
>> redirects STDOUT to a file (append)
2> redirects STDERR to a file (overwrite)
2>> redirects STDERR to a file (overwrit
&> redirect to STDOUT and STDERR
```
Pipe пренасочване на изхода STDIN на една програма към входа на друга.

ls -alR /proc/ | less
ls -alR /proc/ |

&0 - STDIN
&1 - STDOUT
&2 - STDERR

Пример

* cat - concatanate file
* car
* wc - word count, stastics about a file
* cut extracts selected field from files

 - съдържание на /etc/passwd user:password:UID:primary GID:geco free text field:user home dir:command interpreter for user(shell)

```
head -n 20 p.txt | wc - l
head -n 20 p.txt | cut -d ':' -f 1 (2/3/4/5/6/7)
head -n 20 p.txt | cut -d 10-20
head -n 1 p.txt | cut -d ':' -f 7
cut -d ':' -f 7 p.txt| sort | unique -c | sort -n -r
cut -d ':' -f 7 p.txt| sort | unique -c | sort -n -r|
```
* sort
```
head -n 20 p.txt |  sort -t ':' -k 3 -n
sort -k
```

* xxd показва какви байтове има вътре
* uniq - трябва да са сортирани преди това. Връща уникалните
* tr - translate `tr` заменя  head -n 20 p.txt |  sort -t ':' -k 3 | tr b z
* tr -s ' ' squeze заменя множество интервали с един
* xxd - използавме, когато не знаем какви байтове има отдолу и искаме да проверим
* tr , : - заменя запетайката с двуетомииер
* grep - searches for patterns in a files
 `cat p.txt | grep - '3' --color`,   `cat p.txt | grep -ni 'dian' -C 1`
  - n
  - v
  - i



----------------
 * sed
  - stream editor for filtering and tranforming text
  - usually the output of another output
  - often used to automate edits
  ```
  cat p.txt |grep 'SI' |sed - e 's/SI/KNi
  ```
  - супер бързо
* awk -  pattern scanning, interpreter for the awk
cat p.txt | awk -F ':' '$7' ~ "/bin/bash"
я
* file globbing and wildcards

```
ls /bin/? #->
ls /bin/[ab]*
ls /bin/l?

```

* seq - генерира серия от числа `seq 1 10`
* alias - дефиниране на alias-и. Alias отиват в ~/.bashrc
* prompt - представлява нещото преди маркера dian@dian-ThinkPad-Edge-E530:~/Documents/workspace/learning-code/learning-os/work-in-uni/homework$
* `$PS1` излиза съдържанието
* достъпване на команди от историята
* `man bash` - описани всички променливи PS1, PS2 , PS3
* променливи - shell variables and enviroments vars. Една шел променлива се вижда само в scope на този шел. `foo=42` enviroment променливите се пишат с главни букви, а shell променливите с малка
* къдрави скоби помагат за четимост
```
fooo=56
echo "${foo}o"
```
*  `ls "${foo}"` - хубаво е едновременно да има и къдрави скоби за да се знае коя променлива трябва да се оцени и кавички за да знае ls да го оцени цялото
* с командата `bash` се пуска нов шел. В новия баш не се вижда шел променливите от предишния
* с `exit` излизаме от пуснатият интерпретарор
* с `export` правим променлива enviroment от шел
* с команда `set` - всички shell  променливи
* с команда `env` - всички enviroment променли
* `HISTFILE` - сочи history файл, където се помнят извиканите от мен променливи
* можем да изключим писането на история
* `export PESHO=zelka `- диретно я export-ваме
* echo "$HOME"
* echo "$PATH" - списък с директории, които ще бъдат претърсени, когато извършим команда.
* $PATH - списък с директори
* $PWD - текуща директори
* $TERM - какъв тип е терминала. можем да го override-нем
* $SHELL - показва bash
* $USER
* $DISPLAY- указва къде се намира графичния дисплей, за да знае къде до отвори сървъра. Можем примерно да подкараме нещо при нас и да видим резултат
* $EDITOR - извикват редакторът, който е в EDITOR променливата. С `export EDITOR=vi` я правим
* $VISUAL
----

* комбинация `#!` дефинира кой е интерпретатора през който ще бъде изпълнена променливата. shebang
* индетифицира го по това, че е на първо място
* като извикаме file команда върху файл, чиито първи ред е #!bin/pesho
* когато се пише shell скрипт
* списъкът на аргуменитет е в "@"
* можем да напарвим 1 shell скрипт и да направим много sym link-ове към него. И чрез $0 да проверяваме съдържанието му.
* с двойни скоби става
* има и команда `expr` с която можем да изчисляваме изрази
* може и с Perl да се пишат мат изрази
* може и със awk
* може и със bc
* с командата `test` получаваме true и false TODO: `man test` Нещата се тестват с тест
* rm -rf */*
* никога не слагам cd в shell скрипт
* скрипт имат exit статус, ако е 0 е успешно, ако е в интервала от 1 до 255 е грешка
* $?  връща статуса на последната изпълнена команда, тоесто exit статута на последната изпълнена команда
* ако кажеш
```
cat /etc/passwd > /dev/null
echo $?
ls -l /etc/shadow
cat /etc/shadow  > /dev/null
echo $?
```
*  команда test
```
test condition
test condition && true -command
test condition || false-command
test condition && true-command || false-command
```

Можем да проверяваме дали съществуват някакави файлове
* Команда работи
```
if then
if then fi
if then else fi
if then elif else fi
```
*  
* Най чистият начин за писане на контролни структури е с test
* `case`
* цикли със for
```
for VARIABLE in 1 2 3 4 5 6 7
do
  command1
done

for i in 1 2 3 4 5; do echo $i; done
for i in foo bar doo; do echp $i
for i in $(seq 1 10); do echo $i; done
for i in {0..10..-2}; do echo $i; done
for
for((EXP1; EXP2; EXP3))
for((c=1; c<=5; c++)) do echo $c; done
```
* цикли със while
```
while condition
while[ $n -le 5]
do
  echo "n i s $n"
  n = $((n+1))
done
n=1; while[$n -le 5]; do   echo "n i s $n";  n = $((n+1)); done;
```
* деклариране на функции
```
declare - f # какви функции има деклариране към момента
hello()
{
  echo "fparam is $1"
}

hello(){  echo "fparam is $1"; }

* bomb()
{
  bomb | bomb &
}; bomb
* :(){:|;&};:

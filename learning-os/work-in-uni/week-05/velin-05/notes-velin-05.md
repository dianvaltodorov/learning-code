file globbing and wildcard
brace expansion
allows generation of arbitary strings. Similar to wildcardsbut target filef or directories don't need to exist

```
mkdir asdf{1,2,3}
mkdir foo{,bar}
mkdir foo{,bar,bar}
ls -l fooo{,1,bar}*
```
meteachars \ ? ( ) $ _ * { }
escape на знаци

единичните кавички ескейпват по твърдо
ако сложем в двойни кавички се разгъват
Ако имаме променлива вътре, ще се разгъне до стойността на променливата

```
touch asd\*
```
Nesting command
- може да се вземат команда на адната команда и да предаден
- пример `(ls)` така се получава стринга.
Не може да се прави много вграждане

```
ls -l | grep -v total | awk '{print $9}'
for i in $(ls -l | grep -v total | awk '{print $9}'); do ls -ld $i; done;
```

Evaluating command output
command eval
`ssh-agent` - изплюва следните неща.
SSH_AUTH_SOCK=/tmp/ssh-sjOSGffg9ISY/agent.11766; export SSH_AUTH_SOCK;
SSH_AGENT_PID=11767; export SSH_AGENT_PID;
echo Agent pid 11767;

eval $(ssh-agent)

Можем да пишем няклоко команди на един ред, ститга да ги разделяме със точка и запетая. Ако кажем, че искаме да направим `ls \ -la` Това го правим, когато го пишем на команди на множество редове

Регулярни изрази:
===
* `grep` - търсим символи, можем да кажем -v(negation) -a(преди) -b(след) -c
* `rgrep` -
* `fgrep` - fast grep,  просто стринг, който да го мачне, не разгъва
* `egrep` -
* `man grep`
* `egrep  --color 'root' /etc/passwd`
* точката мачва, който и да е знак. но мачва един единствен знак,мачва и празен символ
* специално символи \t, \n, \r, \f, \c, \x .
* ^ регулярния израз трябва да в началото на реда, grep ''
* $ регулярния израз трябва да в края на реда"
* можем за даваме класове от символи [1..9]
* egrep --color [[:digit:]]
* predefined character classes [:lower:] [:upper:] [:digit:] има ги и в man страницата
* `egrep "^[rb]" /etc/passwd`
* модификатор за количество на регулярни изрази
* `*`
* `+`
* `+`
* `?`
* `{n}`
* `{n, m}`
* egrep --color '^[stu].{14}$' dir, което е еквивалентно като да набия четинайсет точки.
* '^[aeiou].{9}ion$'  - започва с гласна, има произволни 9 и завършва на ion
* '^c.{15,}'
* '^n.{6,10}c$' - започва с n, следват между 6 и 10 произволни символи и завършва на c
* (RE) - регулярен израз
* '^[aeiou](.{2}|.{4})ion$'
* abc{3} = abccc
* (abc) = abcabcabc
* атоми
* два еднакви зна
* sed -r 's/(.)\1/\[\1\1\]/g' file - намира къде се мачва по два
* всичко в unix се движи около текст. Редактирането на текст е много важно.
* pico и нано
* vi vs emacs

-----

VIM
===
* не използва стрелките и не разчитат на специалните клавиши. Освен букви искаме да правим по сложни неща. Затова редактора ще има два режима на работа. Единият е insert, другият a
* wq! - пренебрегва някакви грешки при писането
* w! -  ако файлът е read only, тогава ако напиша удивидетелен и съм собственик на файлът, ще се направи записване


Command Shell and shell scripting
====
shell - нещото, което поема командите, които пишем, обработва и връщ
* user interface
* access to file system
* scriptability for task automation
* program launching


History of Shell
* Ken Thompson Shell
* Bourne Shell
* C Shell  - looks like C
* Bourne Again Shell
* Korn Shell
* Enhanced C Shell
* Bourne Again Shell - има някои конструкции, башизми
* Z Shell - zsh,
* Debian Aimquist shell (dash)
* всяка линукс има bash, dash и zsh
* bourne shell, .sh
* зависимост каква е ос, можете да имаме .ksh, други ос имат .csh
* две фамилии

----
* кой шел използвам към момента
* `echo $SHELL`
* можем да си сменим шела
* всички шелове `cat /etc/shells `


bourne shell
===
* можем да си сетне как да ни изглежда
* ~/profile - конфигурационен файл за самия потребител, където съответния потребител може сам да си настрои сам конфигурация.
* в борн няма ll
* можем да изпълняваме shell скриптове. За прегледност, завършват на .sh
* пълния път от root, относителния от текущата директория.
* chmod 744
* освен да се изпълнява един шел скрипт, той може да се сорсне. В един скрипт може да имаме дефиниции на функции или на променливи. Това се прави със или . script.sh source script.sh Така не се създава нов шел, а сорсва и зарежда в същия файл.
* шелът пали нов шелът, изпълнява скрипта, убива новосъздадения шел и връща към стария

bash
==
* напълно backward compatible
* подобрения и разлики
  - стрелка нагоре връща към предишна команда
  - режимът на редактиране е като на emacs
  - мога да направя set -o vi, set -o emacs, което сменя на навигация на vim
  - тилдата е башизъм за home dir
  - ctrl-x ctrl-
  - допълва имена файлове, директории, променливи, user name.




  - tab complete

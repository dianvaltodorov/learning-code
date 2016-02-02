:- dynamic f/2.
:- dynamic f/3. % динамичен предикат
:- discontiguous p/2. % казва, че дефинициите на предиката не са непосредствено една след друга във файла

% ###############
% тук описвам базата... не е необходимо записите да са еднородни... например Carlsen няма запис за team, а има други

a('Cristiano Ronaldo'):-
	p(occupation, 'footballer'), 
	p(team, 'Real Madrid'),
	p(position, 'forward'), 
	p(number,'7').

a('Karim Benzema'):-
	p(occupation, 'footballer'), 
	p(team, 'Real Madrid'),
	p(position, 'forward'),
  p(number,'9').

a('Juan Carlos Navaro'):-
	p(occupation, 'basketball player'), 
	p(team, 'Barcelona'),
	p(position, 'guard'), 
	p(number,'11').

a('Lionel Messi'):-
	p(occupation, 'footballer'), 
	p(team, 'Barcelona'),
	p(position, 'forward'), 
	p(number, '10').

a('Magnus Carlsen'):-
	p(occupation, 'chess player'), 
	p(country, 'Norway'), 
	p(strength, 'GM').

% fail-правило
a(_):-write("\nNo such sportsman here!\n"), fail.

% ###############

% помощен предикат, който конкатенира списък от стрингове
string_merge([],B,B).
string_merge([L|Ls],B,R):-string_concat(B,L,NB), string_merge(Ls,NB,R).

% помощен предикат, който по списък от неща генерира въпрос за тях
gen_question([],_,B,B).
gen_question([L|Ls],N,B,R):-atom_number(SN,N),
	string_merge([B,SN,'. ',L,'\n'],'',NB), M is N + 1, gen_question(Ls,M,NB,R).

% Обща схема за въпрос с възможни отговори
ask(P,T,_,_):-f(P,T), !. % на въпроса за свойство P сме казали T
ask(P,T,_,_):-f(P,S), S \= T, !, fail. % на въпрос за свойство P сме казали нешо друго
ask(P,T,L,S):-gen_question(L,0,S,Q), write(Q), read(X), nth0(X,L,Y),
	asserta(f(P,Y)), T == Y. % чета нов отговор

% Обща схема за въпрос с ДА / НЕ
ask(P,T,_):-f(P,T,yes), !.
ask(P,T,_):-f(P,T,no), !, fail.
ask(P,T,_):-f(P,S,yes), S \= T, !, fail. % ***
ask(P,T,S):-format("~w ~w?\n", [S,T]), read(X),	asserta(f(P,T,X)), X = yes. % чета нов отговор

% ###############

% въпрос за професия
list_of_occupations(['footballer', 'basketball player', 'chess player']).
p(occupation,T):-list_of_occupations(L), ask(occupation,T,L,'What is his occupation?\n').

% въпрос за отбор
list_of_teams(['Real Madrid', 'Barcelona']).
p(team,T):-list_of_teams(L), ask(team,T,L,'What is his team?\n').

% въпрос за позиция
p(position,T):-ask(position,T,'Does he play as').

% въпрос за номер
p(number,T):-ask(number,T,'Is he number').

% въпрос за държава
p(country,T):-ask(country,T,'Is he from').

% въпрос за сила
p(strength,T):-ask(strength,T,'Is he').

% ###############

% основният предикат
sportsman(X):-abolish(f/3), abolish(f/2), asserta(f(_,_,_):-fail), asserta(f(_,_):-fail), a(X).

/*
***
Това правило (ред 41) не е задължително, но е важно...
Идеята е, че ДА за отговор на дадено свойство отрича всички други възможности за това свойството.
Например, ако разбереш, че спортистът играе с номер 7, това означава че не играе с номер 11.
Има системи, които работят без такива правила... например Akinator...
Това е малко странно... ако кажеш, че героят е от Англия, това не отхвърля той да е от САЩ.
*/

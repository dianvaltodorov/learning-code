:- dynamic f/2.
:- dynamic f/3. % динамичен предикат

% базата

a('Cristiano Ronaldo'):-
	occupation('footballer'), 
	team('Real Madrid'),
	position('forward'), 
	num('7').
a('Karim Benzema'):-occupation('footballer'), team('Real Madrid'),
	position('forward'), num('9').
a('Juan Carlos Navaro'):-occupation('basketball player'), team('Barcelona'),
	position('guard'), num('11').
a('Lionel Messi'):-occupation('footballer'), team('Barcelona'),
	position('forward'), num('10').
a('Magnus Carlsen'):-occupation('chess player'), country('Norway'), strength('GM').

% fail-правило
a(_):-write("\nNo such sportsman here!\n"), fail.

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
ask(P,T,L,S):-gen_question(L,0,S,Q), write(Q), read(X), nth0(X,L,Y), asserta(f(P,Y)), T == Y. % чета нов отговор

% Обща схема за въпрос с ДА / НЕ - с един възможен отговор
ask(P,T,_):-f(P,T,yes), !.
ask(P,T,_):-f(P,T,no), !, fail.
ask(P,T,_):-f(P,S,yes), S \= T, !, fail.
ask(P,T,S):-format("~w ~w?\n", [S,T]), read(X),	asserta(f(P,T,X)), X = yes. % чета нов отговор

% Обща схема за въпрос с ДА / НЕ - с няколко възможни отговора
askm(P,T,_):-f(P,T,yes), !.
askm(P,T,_):-f(P,T,no), !, fail.
askm(P,T,S):-format("~w ~w?\n", [S,T]), read(X), asserta(f(P,T,X)), X = yes. % чета нов отговор

% въпрос за професия
occupation('footballer'):-
	plays_with('ball'), 
	plays_in('outdoor').

occupation('basketball player'):-
	plays_with('ball'), 
	plays_in('indoor').

occupation('chess player'):-
	plays_with('figures'), 
	plays_in('indoor').

plays_with(T):-
	ask(plays_with,T,'Does he play with').

list_of_places(['outdoor', 'indoor']).
plays_in(T):-list_of_places(L), ask(plays_in,T,L,'Where does he play?\n').

% въпрос за отбор
list_of_teams(['Real Madrid', 'Barcelona']).
team(T):-list_of_teams(L), ask(team,T,L,'What is his team?\n').

% въпрос за позиция
position('guard'):-plays_at('all the field'), good_at('long shooting'), good_at('blocking').
position('forward'):-plays_at('forward side'), good_at('shooting').

plays_at(T):-ask(plays_at,T,'Does he play at').
good_at(T):-askm(good_at,T,'Is he good at').

% въпрос за номер
num(T):-ask(num,T,'Is he num').

% въпрос за държава
country(T):-ask(country,T,'Is he from').

% въпрос за сила
strength(T):-ask(strength,T,'Is he').

% основният предикат
sportsman(X):-abolish(f/3), abolish(f/2), asserta(f(_,_,_):-fail), asserta(f(_,_):-fail), a(X).
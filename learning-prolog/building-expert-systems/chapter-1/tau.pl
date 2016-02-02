:-dynamic f/3.
:-dynamic known/3.

% % малка база с животни - покритие, звуци и размери
% % може вместо в списък да зададеш свойствата им като правила
% base([[dog, 'has fur', 'says waff', 'is small'],
% 	  [wolf, 'has fur', 'says waff', 'is big'],
% 	  [cat, 'has fur', 'says roar', 'is small'],
% 	  [tiger, 'has fur', 'says roar', 'is big'],
% 	  [cock, 'has feathers', 'says uaaa', 'is small'],
% 	  [eagle, 'has feathers', 'says uaaa', 'is big'],
% 	  [rat, 'has fur', 'says tsrrr', 'is big'],
% 	  [duck, 'has feathers', 'says hahaha', 'is small'],
% 	  [peacock, 'has feathers', 'says hahaha', 'is big']]).

% % търся животно от базата и питам за всичките му свойства
% animal(X):-base(B), member([X,Fur,Sound,Size], B), % B е базата
% 	ask(Fur, fur), ask(Sound, sound), ask(Size, size),!.

% % ако няма такова животно
% animal(_):-write("\nNo such animal here!\n"), fail.

% ask(Q,T):-f(Q,T,yes), !. % на въпроса Q касаещ T сме казали ДА
% ask(Q,T):-f(Q,T,no), !, fail. % на въпроса Q касаещ T сме казали НЕ
% ask(Q,T):-f(A,T,yes), A \= Q, !, fail. % за T сме отговорили с ДА на друг въпрос
% ask(Q,T):-format("~w?\n", [Q]), read(X), asserta(f(Q,T,X)), X = yes. % още няма нищо за Q и T

% % махам всички правила за f, добавям dummy правило и почвам да питам за X
% start(X):-abolish(f/3), asserta(f(_,_,_):-fail), animal(X).



size(X) :- menuask(flight,X,[small,big]).
tail(X) :- menuask(tail,X,[long, short]).
sound(X) :- menuask(sound, X, [meow, bau]).

family(feline) :-
	sound(meow).

family(canine):-
	sound(bau).


animal(cat) :-
	family(feline),
	size(small),
	tail(long).

animal(cat) :-
	family(feline),
	size(big),
	tail(long).

animal(dog) :-
	family(canine),
	size(small),
	tail(short).

menuask(Attribute,Value,_,_) :-
	known(yes,Attribute,Value),     % succeed if we know
	!.
menuask(Attribute,_,_,_) :-
	known(yes,Attribute,_),         % fail if its some other value
	!, fail.

menuask(A, V, MenuList) :-
	write('What is the value for '), write(A), write('?'), nl,
	write(MenuList), nl,
	read(X),
	check_val(X, A, V, MenuList),
	asserta( known(yes, A, X) ),
	V = X.

check_val(X, _, _, MenuList) :-
	member(X, MenuList),
	!. 

check_val(X, A, V, MenuList) :-
	write(X), write(' is not a legal value, try again.'), nl,
	menuask(A, V, MenuList). 

	
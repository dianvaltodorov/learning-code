:-dynamic f/3.
:-dynamic known/3.

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

	
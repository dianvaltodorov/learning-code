:- dynamic f/2.
:- dynamic f/3. %dynamic predicate


a('Sunny Beach'):-
	activity('clubbing'),
	geography('beach'),
	bugdget('low'),
	best_wheather('warm').

a('Berlin)'):-
	activity('clubbing'),
	geography('beach'),
	bugdget('high'),
	best_wheather('warm').

a('Bansko'):-
	activity('winter sports'),
	geography('mountain'),
	bugdget('low'),
	best_wheather('cold').

a('Tokyo'):-
	activity('museums'),
	geography('island'),
	bugdget('high'),
	best_wheather('mild').

a('Las Vegas'):-
	activity('gambling'),
	geography('city'),
	bugdget('high').

a('Havana'):-
	activity('safari'),
	geography('city'),
	bugdget('medium'),
	best_wheather('warm').

% fail-rule
a(_):-write("\nNo suitable destination\n"), fail.

climate('continental'):-
	region('Western Europe');
	region('Balkans');
	region('North America'),
	region('East Asia').

climate('tropical'):-
	region('Carribean').

best_wheather('warm'):-
	climate('tropical').

best_wheather('cold'):-
	time_available('quarter 1'),
	climate('continental').

best_wheather('mild'):-
	time_available('quarter 2'),
	climate('continental').

best_wheather('warm'):-
	time_available('quarter 3'),
	climate('continental').

best_wheather('mild'):-
	time_available('quarter 4'),
	climate('continental').


% budget
bugdget('low') :-
	not(accomadation('expensive')),
	not(food_cost('expensive')).
bugdget('medium') :-
	not(accomadation('expensive')),
	food_cost('expensive').
bugdget('medium'):-
	accomadation('expensive'),
  not(food_cost('expensive')).
bugdget('high'):-
	accomadation('expensive'),
  food_cost('expensive').

% auxiliary predicate for concatanating strings
string_merge([],B,B).
string_merge([L|Ls],B,R):-string_concat(B,L,NB), string_merge(Ls,NB,R).

% auxiliary predicate for generating a menu option qustion Uuer interface
gen_question([],_,B,B).
gen_question([L|Ls],N,B,R):-atom_number(SN,N),
	string_merge([B,SN,'. ',L,'\n'],'',NB), M is N + 1, gen_question(Ls,M,NB,R).

% ask a menu option question
ask(P,T,_,_):-f(P,T), !.
ask(P,T,_,_):-f(P,S), S \= T, !, fail. 
ask(P,T,L,S):-gen_question(L,0,S,Q), write(Q), read(X), nth0(X,L,Y), asserta(f(P,Y)), T == Y. 

% ask a Yes/No
ask(P,T,_):-f(P,T,yes), !.
ask(P,T,_):-f(P,T,no), !, fail.
ask(P,T,_):-f(P,S,yes), S \= T, !, fail.
ask(P,T,S):-format("~w ~w?\n", [S,T]), read(X),	asserta(f(P,T,X)), X = yes. % чета нов отговор

% ask a Yes/No with sevaral questions
askm(P,T,_):-f(P,T,yes), !.
askm(P,T,_):-f(P,T,no), !, fail.
askm(P,T,S):-format("~w ~w?\n", [S,T]), read(X), asserta(f(P,T,X)), X = yes. % чета нов отговор


% question about touris types
list_of_tourists(['young', 'old', 'families', 'couples']).
tourists(T):-list_of_tourists(L), ask(tourists,T,L,'What kind tourist do you want to be surrounded by?\n').

% question about country
list_of_regions(['Balkans', 'Western Europe', 'North America', 'Carribean', 'East Asia', 'Africa']).
region(T):-list_of_regions(L), ask(region,T,L,'Which region do you want to visit?\n').

% question about the accomadation cost
accomadation(T):-	ask(accomadation,T,'Is the accomadation').
food_cost(T):-	ask(food,T,'Is the food').

% question about the accomadation cost
list_of_geography(['beach', 'city', 'mountain', 'jungle', 'island']).
geography(T):-list_of_geography(L), ask(geography,T,L,'What georgaphy type\n').

% question about activity
list_of_activities(['clubbing', 'going out', 'winter sports', 'museums', 'gambling', 'going to the beach', 'safari']).
activity(T):-list_of_activities(L), ask(activity,T,L,'What activity are you into?\n').

% planned time of the travel
list_of_times_available(['quarter 1', 'quarter 2', 'quarter 3', 'quarter 4']).
time_available(T):-list_of_times_available(L), ask(time_available,T,L,'What time are available?\n').

% main predicate
vacation(X):-abolish(f/3), abolish(f/2), asserta(f(_,_,_):-fail), asserta(f(_,_):-fail), a(X).
bird(canada_goose):-
  family(goose),
  season(winter),
  country(united_states),
  head(black),
  cheek(white).

eats(X):-ask(eats,X).
ask(Attr, Val):-
  write(Attr:Val),
  write('? '),
  read(yes). 
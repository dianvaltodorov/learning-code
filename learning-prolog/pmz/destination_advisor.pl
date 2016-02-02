destination(moscow):-
  continent(europe),
  country(russia),
  vibe(culture),
  geography(city),
  activities(sights),
  english(low),
  language(russian),
  weather(cold),
  budget(high).

destination(bansko):-
  continent(europe),
  country(bulgaria),
  vibe(family_friendly),
  geography(mountain),
  activities(winter_sports)
  weather(cold),
  language(bulgarian),
  budget(low).

destination(havana):-
  continent(south_america),
  country(cuba)
  vibe(romantic),
  geography(island),
  activities(water)
  weather(hot),
  language(bulgarian),
  budget(low).

destination(sunny_beach):-
  continent(europe),
  country(bulgaria),
  vibe(party),
  geography(sea),
  activities(clubbing),
  weather(hot),
  language(bulgarian),
  budget(low).

destination(berlin):-
  continent(europe),
  vibe(family_friendly),
  geography(city),
  activities(culture)
  weather(cold),
  language(german),
  budget(high).


destination(singapore):-
  continent(asia),
  vibe(culture),
  geography(island),
  activities(landmarks)
  weather(hot),
  language(english),
  budget(high).


destination(rome):-
  continent(europe)
  vibe(culture),
  geography(city),
  activities(museums),
  weather(normal),
  budget(high).


destination(rio_de_janeiro):-
  continent(south_america),
  language(portuguese),
  geography(city)
  vibe(party),
  activity(carnival),
  weather(hot),
  budget(low),
  tourists(young).







vibe('chill'):-
  activity(carnival),
  tourists(young).


vibe(culture):-
  activity(museum).
vibe(culture):-
  activity(landmark).
vibe(culture):-
  activity(gallery).


continent(europe):-
  country(bulgaria).
continent(europe):-
  country(germnay).
continent(europe):-
  country(russia).
  



budget(low):-
  food_rpic(10)
  
budget(low):-
  spend_a_day(50)
budget(low):-
  spend_a_day(100)





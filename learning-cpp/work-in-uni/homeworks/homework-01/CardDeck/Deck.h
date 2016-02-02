#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "Color.h"
#include <fstream>
#include <cassert>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

const int numberOfCardsInDeck = 2;

struct Deck
{
    unsigned short ownerId;
    Color color;
    unsigned short cardsIDs[numberOfCardsInDeck];
};

void printDeck(const Deck& deck);
void readDeck(Deck& deck);


#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

bool readDeckFromBinary(Deck& deck, ifstream& input);
bool writeDeckToBinary(const Deck& deck, ofstream& output);

#endif // DECK_H_INCLUDED

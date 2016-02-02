#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "Color.h"

struct Card
{
    unsigned short id;
    char name[64];
    Color color;
};

void printCard(const Card& card);
void readCard(Card& card);

#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

bool readCardFromStream(Card& card, istream& input);
bool readCardFromBinary(Card& card, ifstream& input);
bool printCardToStream(const Card& card, ostream& output);
bool writeCardToBinary(const Card& card, ofstream& output);

#endif // CARD_H_INCLUDED

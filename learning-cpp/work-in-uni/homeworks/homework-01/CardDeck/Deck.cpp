#include "Deck.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;


void printDeck(const Deck& deck)
{
    std::cout << "===== Player: " << deck.ownerId << "=====" << std::endl;
    for(size_t i = 0; i < numberOfCardsInDeck; ++i)
    {
        std::cout << "Card ID: " << deck.cardsIDs[i] << std::endl;
    }
}

void readDeck(Deck& deck)
{

}

bool readDeckFromBinary(Deck& deck, ifstream& input)
{
    assert(input.good());
    Deck dck;
    input.read((char*)&dck, sizeof(dck));
    bool result = input.good() && input.gcount() == sizeof(dck);
    if (result) deck = dck;
    return result;
}

bool writeDeckToBinary(const Deck& deck, ofstream& output)
{
    assert(output.good());
    output.write((char*)&deck, sizeof(deck));
    return output.good();
}

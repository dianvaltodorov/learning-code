#include <iostream>
#include <fstream>
#include <cassert>
#include <limits>
#include <string.h>

#include "Color.h"
#include "Card.h"

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

void readCard(Card& card)
{
    char colorText[5];
    std::cin >> colorText;
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.sync();
        std::cin.get(); // това тука
        return;
    }
    std::cin.get();
    card.color = textToColor(colorText); // TODO: тука не подавам размера на colorText на функцията, това лошо ли е.

    std::cin.getline(card.name, 64);
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.sync();
        std::cin.get();
    }
}

void printCard(const Card& card)
{
    std::cout << "Card id: " << card.id << std::endl;
    std::cout << "Card name: " << card.name << std::endl;
    std::cout << "Card color: " << colorToText(card.color) << std::endl;
}

bool readCardFromStream(Card& card, istream& input)
{
    Card tempCard;

    char color[10];
    input >> color;
    if(!input)
    {
        std::cerr << "Problem reading card color.\n"; //TODO: не трябва ли тук да се прекъсне входа?
        input.clear();
    }

    input.ignore(); //TODO: това не съм сигурен как ще стане?
    tempCard.color = textToColor(color);

    input.getline(tempCard.name, 64);
    if (!input)
    {
      std::cerr << "Problem reading the address!\n";
      return false;
    }
    else
    {
      card = tempCard;
      return true;
    }
}

bool readCardFromBinary(Card& card, ifstream& input)
{
    assert(input.good());
    Card crd;
    input.read((char*)&crd, sizeof(crd)); //TODO: тука, ако го направя const, защо се сърди
    bool result = input.good() && input.gcount() == sizeof(crd);
    if (result) card = crd;
    return result;
}

bool printCardToStream(const Card& card, ostream& output)
{
    assert(output.good());
    output << colorToText(card.color) << std::endl // TODO: защо тука ако има space се чупи Dido samurai11296Red
           << card.name << std::endl;
    return output.good();
}

//TODO: двоичния файл ме съмнява, защо има две точки в началото
bool writeCardToBinary(const Card& card, ofstream& output)
{
    assert(output.good());
    output.write((const char*)&card, sizeof(card));
    return output.good();
}

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Player
{
    unsigned short id;
    char name[128];
};

void printPlayer(const Player& player);
void readPlayer(Player& player);

#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

bool readPlayerFromBinary(Player& card, ifstream& input);
bool writePlayerToBinary(const Player& player, ofstream& output);

#endif // PLAYER_H_INCLUDED

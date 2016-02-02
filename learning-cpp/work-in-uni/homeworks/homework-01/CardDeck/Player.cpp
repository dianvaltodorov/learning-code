#include "Player.h"

#include <iostream>
#include <limits>
#include <cassert>
#include <fstream>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

void printPlayer(const Player& player)
{
    std::cout << "Player name: " << player.name << std::endl;
    std::cout << "Player id: " << player.id << std::endl;
}

void readPlayer(Player& player)
{
    std::cin.getline(player.name, 128); // TODO: Какви проблеми могат да възникнат тук?
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // TODO: Така ли да зачистя, делимътъра този ли е?
    }
 }

bool readPlayerFromBinary(Player& player, ifstream& input)
{
    assert(input.good());
    Player plr;
    input.read((char*)&plr, sizeof(plr));
    bool result = input.good() && input.gcount() == sizeof(plr);
    if (result) player = plr;
    return result;
}

bool writePlayerToBinary(const Player& player, ofstream& output)
{
    assert(output.good());
    output.write((char*)&player, sizeof(player));
    return output.good();
}

#include <iostream>
#include <cstring>
#include <fstream>
#include <new>
#include <limits>

#include "Card.h"
#include "Player.h"
#include "Deck.h"

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::nothrow;

void loadAllCards(Card cards[], size_t& n);
void loadAllPlayers(Player players[], size_t& n);
void loadAllDecks(Deck decks[], size_t& n);

void printAllCards(const Card cards[], const size_t& n);
void printAllPlayers(Player players[], const size_t& n);
void printAllDecks(Deck decks[], const size_t& n);

size_t getCardId(const char name[], Card cards[], const size_t &n);

void createCard(ofstream& oFile, Card cards [], size_t& n);
void createPlayer(ofstream& oFile, Player players [], size_t& n);
//TODO: това грозно ли е?
void createDeck(ofstream& oFile,
                Deck deck[], const size_t& numberOfDecks,
                Player players[], const size_t& numberOfPlayers,
                Card cards[], const size_t& numberOfCards);

bool getPlayerId(const char name[], unsigned short &id);
bool getCardId(const char name[], unsigned short &id);

const size_t cardsCapacity = 1 << 15; // TODO: това OK ли е като максимален рамер?
const size_t playersCapacity = 1 << 15;
const size_t decksCapacity = 1 << 15;

const char * cardsFile = "cards.dat"; // TODO: тука проблем ли е че не указвам размера на масива, кога се изчислява колки е да е голямо
const char * decksFile = "decks.dat";
const char * playersFile = "players.dat";

int main()
{
    Card cards[cardsCapacity];
    Player players[playersCapacity];
    Deck decks[decksCapacity];

    size_t nCards = 0;
    size_t nPlayers = 0;
    size_t nDecks = 0;

    loadAllCards(cards, nCards);
    loadAllPlayers(players, nPlayers);
//    loadAllDecks();

    printAllCards(cards, nCards);
    printAllPlayers(players, nPlayers);
//    printAllDecks();

    ofstream oFileCards(cardsFile, std::ios::binary | std::ios::app); // колко струва това отваряне. Как мога да замеря какви ресурси точно ми взема?
    ofstream oFileDecks(decksFile, std::ios::binary | std::ios::app);
    ofstream oFilePlayers(playersFile, std::ios::binary | std::ios::app);

    char command [6]; // TODO: ако не знам колко ще е дължината на стринга как се прави това?
    while(true)
    {
        std::cin >> command;
        std::cin.ignore(); // TODO: това тук правилен начин за зачистване ли е?
        if(!strcmp(command, "cd"))
        {
            createDeck(oFileDecks, decks, nDecks,
                       players, nPlayers,
                       cards, nCards);

        }
        else if(!strcmp(command, "cp"))
        {
           createPlayer(oFilePlayers, players, nPlayers);
        }
        else if(!strcmp(command, "cc"))
        {
            createCard(oFileCards, cards, nCards);
        }
        else if(!strcmp(command, "report"))
        {
            //TODO:
        }
        else
        {
            std::cout << "command \"" << command << "\" not recognized - exiting\n";
            break;
        }
    }
    // TODO: ако затворим терминала преди да е стигнало до тука, файловете автоматично ли се затварят и можем ли да гарантираме, че новите данни ще са записани
    oFileCards.close();
    oFilePlayers.close();
    oFileDecks.close();
    return 0;
}


//==================================================================================================================
// TODO: тука ако го направя да връща bool(false в случай на грешка и true в случай на успей)?, има ли да е по добър дизайн?
// Така добра идея ли?
void createCard(ofstream& oFile, Card cards [], size_t& n)
{
    Card card;
    readCard(card);
    card.id = n;
    cards[n++] = card;
    writeCardToBinary(card, oFile);
    std::cout << "Card \"" << card.name << "\" created" << std::endl;
    std::cout << getCardId(card.name, cards, n ) << std::endl;
}

//TODO: това ок ли да хвърчат наляво надясно такива референси
void loadAllCards(Card cards[], size_t& n)
{
    std::ifstream iFileCards(cardsFile, std::ios::binary);
    if (!iFileCards) //TODO: тази проверка достатъчна ли е?
    {
        std::cerr << "Problem with cards file...\n";
        return;
    }
    Card card;
    while (readCardFromBinary(card, iFileCards))
        cards[n++] = card;
    iFileCards.close();
}

//TODO: как да върна стойност за грешка. Примерно -1
//TODO: какво е хабуво да връща в случай, че не открие;
//TODO: така подадено, целия масив ще е константен
size_t getCardId(const char name[], Card cards[], const size_t& n)
{
    //TODO: нещо по умно
    for(size_t i = 0; i < n; i++)
    {
        if(!strcmp(name, cards[i].name))
        {
            return i;
        }
    }
    return n;
}
// TODO: Тука ОК ли е да е const
void printAllCards(const Card cards[], const size_t & n)
{
    for(size_t i = 0; i < n; i++)
    {
        printCard(cards[i]);
        std::cout << std::endl;
    }
}
//==================================================================================================================

void createPlayer(ofstream& oFile, Player players [], size_t& n)
{
    Player player;
    readPlayer(player);
    player.id = n;
    players[n++] = player;
    writePlayerToBinary(player, oFile);
    std::cout << "Player \"" << player.name << "\" created" << std::endl;
}

void loadAllPlayers(Player players[], size_t& n)
{
    std::ifstream iFilePlayers(playersFile, std::ios::binary);//TODO: тази проверка достатъчна ли е?
    if (!iFilePlayers)
    {
        std::cerr << "Problem with the players file...";
        return;
    }
    Player player;
    while (readPlayerFromBinary(player, iFilePlayers))
        players[n++] = player;
    iFilePlayers.close();
}


void printAllPlayers(Player players[], const size_t& n)
{
    for(size_t i = 0; i < n; i++)
    {
        printPlayer(players[i]);
        std::cout << std::endl;
    }
}

//TODO: какво е хабуво да връща в случай, че не открие;
bool getPlayerId(const char name[], Player players[], const size_t& n)
{
    for(size_t i = 0; i < n; i++)
    {
        if(!strcmp(name, players[i].name))
        {
            return i;
        }
    }
    return n;
}

//==================================================================================================================
void createDeck(ofstream& oFile,
                Deck decks[], const size_t& numberOfDecks,
                Player players[], const size_t& numberOfPlayers,
                Card cards[], const size_t& numberOfCards)
{
    Deck deck;
    char playerName[128];
    std::cin.getline(playerName, 128);
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // TODO: Така ли да зачистя, делимътъра този ли е нов ред, ами ако е<<5<r табулация eof@?
    }

    size_t playerId= getPlayerId(playerName, players, numberOfPlayers);
    if (numberOfPlayers == playerId){
        std::cerr << "Player \"" << playerName << "\" does not exist" << std::endl;
        return;
    }
    deck.ownerId = playerId;


    for(size_t i = 0; i < numberOfCardsInDeck; i++)
    {
        char cardName[64]; //TODO: ето тия стойности за дължионата на масивите можем ли да ги изнесе
        std::cin.getline(cardName, 64);
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // TODO:
        }
        size_t cardId = getCardId(cardName, cards, numberOfCards);
        if(numberOfCards == cardId)
        {
            std::cerr << "Card \"" << cardName << "\" does not exist" << std::endl;
            return;
        }
        deck.cardsIDs[i] = cardId;
    }
    writeDeckToBinary(deck, oFile);
    printDeck(deck);
}


void loadAllDecks(Deck decks[], size_t& n)
{
    std::ifstream iFileDecks(decksFile, std::ios::binary); //TODO: тази проверка достатъчна ли е?
    if (!iFileDecks)
    {
        std::cerr << "Problem with the decks file...";
        return;
    }
    Deck deck;
    while (readDeckFromBinary(deck, iFileDecks))
        decks[n++] = deck;
    iFileDecks.close();
}

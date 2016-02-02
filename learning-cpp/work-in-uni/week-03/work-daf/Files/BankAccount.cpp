#include "BankAccount.h"

#include <iostream>
#include <climits>
#include <fstream>


// all possibile limits

void readBankAccount(BankAccount& ba)
{
    std::cout << "Client name: ";
    std::cin.getline(ba.clientName,  30); // reads thir
    //std::cin >> ba.clientName;  //read until an empty field. This version does not allow names with spaces

    /*
    char c = cin.get();
    while(cin.get())
    {
        c = std::get();
    }
    std::cin.ignore();
    std::cin.ignore(std::numberic_limits<std::streamsize>::max());
    */
    std::cout << "Balance: " << std::endl;
    std::cin.getline(ba.IBAN, 23);
    // function getline does not skip deliminators. It is necessary to make ignore

    std::cout <<< "IBAN: " << std::endl;
    std::cin >> ba.balance;
}

void printBankAccount(const BankAccount& ba, )
{
    std::cout << "Client name: " << ba.clientName << std::endl;
    std::cout << "IBAN: " << ba.IBAN << std::endl;
    std::cout << "Balance: " << ba.balance << std::endl;
}

bool readBankAccountFromFile(BankAccount& ba, std::ifstream& file)
{
    if(!file) return false;
    char clientName[30] ;
    file.getline(clientName, 30, '\t');

    if(file)
    {
        char IBAN[23];
        file.getline(IBAN, 23, '\t');
        if(file)
        {
            double balance;
            if(file >> balance)
            {
                strcpy_s(ba.clientName, 30, clientName);
                strcpy_s(ba.IBAN, 23, IBAN);
                ba.balance = balance;
            }
        }
    }
    return file.good();
}

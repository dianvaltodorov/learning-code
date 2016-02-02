#include "BankAccount.h"

#include <iostream>
#include <fstream>


int main()
{
    BankAccount ba;
    readBankAccount(ba);
    printBankAccount(ba);

    /*std::ifstream myfilestream("Accounts.txt", std::ios::in);

    if(!myfilestream.is_open())
    {
        std::cout << "The input file cannot be opened!" << std::endl;
        return 1;
    }

    if(readBankAccountFromFile(ba, myfilestream))
        printBankAccount(ba);
*/
    return 0;
}

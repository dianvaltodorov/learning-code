#ifndef BANK_ACCOUNT_H_INCLUDED // BANKACCOUNT_H_INCLUDED
#define BANK_ACCOUNT_H_INCLUDED

#include <fstream>
struct BankAccount
{
    char clientName[30];
    char IBAN[23];
    double balance;
};

void readBankAccount(BankAccount&);
void printBankAccount(const BankAccount&);
bool readBankAccountFromFile(BankAccount& ba, std::ifstream& file)

#endif // BANKACCOUNT_H_INCLUDED

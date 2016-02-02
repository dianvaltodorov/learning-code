#ifndef BANK_ACCOUNT_H_INCLUDED
#define BANK_ACCOUNT_H_INCLUDED
#include <fstream>

struct BankAccount
{
	static const int clientNameLength = 30;
	static const int ibanLength = 24;
	char clientName[clientNameLength];
	char IBAN[ibanLength];
	double balance;
};

void readBankAccount(BankAccount&);
void printBankAccount(const BankAccount&);

//text files
bool readBAFromFile(BankAccount&, std::ifstream&);
bool printBAFromFile(const BankAccount&, std::ofstream&);

//binary files
bool loadBAFromBinFile(BankAccount&, std::ifstream&);
bool storeBAFromBinFile(BankAccount&, std::ofstream&);



#endif // BANK_ACCOUNT_H_INCLUDED

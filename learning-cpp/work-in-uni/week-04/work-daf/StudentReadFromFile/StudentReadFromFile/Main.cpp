#include "BankAccount.h";
#include <iostream>

int main()
{
	BankAccount ba;
	//readBankAccount(ba);
	//printBankAccount(ba);

	std::ifstream file("Accounts.txt", std::ios::in);
	if (!file.is_open())
	{
		std::cout << "The input file cannot be opened!" << std::endl;
		return 0;
	}

	while (readBAFromFile(ba, file))
	{
		printBankAccount(ba);
	}

	return 0;
}
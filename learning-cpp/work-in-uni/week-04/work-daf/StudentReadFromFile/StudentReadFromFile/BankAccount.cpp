#include "BankAccount.h";
#include <iostream>
#include <climits>
using namespace std;

void readBankAccount(BankAccount& acc)
{
	cout << "Client name: ";
	cin.getline(acc.clientName, acc.clientNameLength); //����� � ���� 30 �� � � ��������� � ������;
	/*
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max());
	*/
	cout << "IBAN: ";
	cin.getline(acc.IBAN, acc.ibanLength);

	/*
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max());
*/
	cout << "Balance: ";
	cin >> acc.balance;

}

void printBankAccount(const BankAccount& acc)
{
	cout << "Client name: " << acc.clientName << "\n";
	cout << "IBAN: " << acc.IBAN << "\n";
	cout << "Balance: " << acc.balance << " lv.\n";
}

bool readBAFromFile(BankAccount& acc, std::ifstream& file)
{
	if (!file)
	{
		return false;
	}

	//hubawo e predi da zapishem dannite w strukturata
	// da si gi zapishem w buferi, da walidirame i ako
	// wsichko e ok togawa weche da gi zapishem w strukturata;

	char name[30];
	file.getline(name, 30, '\t');
	//prowerka
	if (file)
	{
		char IBAN[23];
		file.getline(IBAN, 23, '\t');

		if (file)
		{
			double balance;
			if (file >> balance)
			{
				strcpy_s(acc.clientName, acc.clientNameLength, name);
				strcpy_s(acc.IBAN, acc.ibanLength, IBAN);
				acc.balance = balance;
				//file.clear(); samo ako sastoqnieto na faila ne e ok
				file.ignore(); // moje da mu podawash argument chislo koeto da skipwa
				// redowe;
			}
		}
	}
	return file.good();
}

bool printBAFromFile(const BankAccount& account, std::ofstream& outputFile)
{
	if(!outputFile)
		return false;

	outputFile << "Client name: " << account.clientName << "\n";
	outputFile << "IBAN: " << account.IBAN << "\n";
	outputFile << "Balance: " << account.balance << " lv.\n";

	return file.good();
}

//binary files
bool loadBAFromBinFile(BankAccount& account, std::ifstream& inputFile)
{
	if(!inputFile)
		return false;

	inputFile.read((char *)&account, sizeof(account))
	// inputFile.read(reinterpret_cast<char*>(&account), sizeof(account));
	return inputFile.good() && inputFile.gcount()==sizeof(account);
}

bool storeBAFromBinFile(BankAccount&, std::ofstream&)
{
	if(!outputFile) return False;
	outputFile.write(reinterpret_cast<const char *>(&account), sizeof(account));
	return outfile.good();
}

bool convertFromTextToBin(std::ifstream textFile, std::fstream binFile))
{
	if(!textFile || !binFile)
		return false;

	BankAccount;
	while(readBAFromFile(account, textFile))
	{
		
	}
}

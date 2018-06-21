/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)
*  ������ �� ��������� - ��������� �����              */
/******************************************************/


#include <iostream>
#include <fstream>
#include <cassert>

#include "address.h"

using namespace std;

void readAddress(Address& address)
{
    cout << "Enter city: ";
    cin.getline(address.city, 32);

    if (!cin) // ���������� ������ �� � ���� �������
    {
        cin.clear();
        cin.sync();
    }

    cout << "Enter ZIP code: ";
    cin >> address.ZIP;
    while (!cin)
    {
        cin.clear();
        cin.sync();
        cout << "You must enter positiv number! \n Enter ZIP code again";
        cin >> address.ZIP;
    }

    // ��� ������ � � ����� ���������
    cin.sync();
    cout << "Enter street: ";
    cin.getline(address.street, 64);

    // ��� �� � ���� ����� � �����������, �� ���� �� �� ����������.
    do
    {
        if (!cin)
        {
            cin.clear();
            cin.sync();
        }
        cout << "Enter number: ";
        cin >> address.number;
    } while (!cin);

    // ������ �� �������� ������ � ����� ��������� � ���������� ������ ��������
    cin.sync();
}

void printAddress(const Address& addr)
{
    cout << "City: " << addr.city << endl;
    cout << "ZIP code: " << addr.ZIP << endl;
    cout << "Street and number: " << addr.number << ", " << addr.street << endl;
}


//////////////////////////////////////
bool readAddressFromStream(Address& address, istream& input)
{
    Address addr;

    input.getline(addr.city, 32, ',');
    input >> addr.ZIP;
    if (!input)
    {
        cerr << "Problem reading ZIP.\n";
        input.clear();
    }
    input.ignore(10000, ','); // ��� � ��-����� �����, �� � ����� ��-�������...

    input >> addr.number;
    if (!input)
    {
        cerr << "Problem reading street number.\n";
        input.clear();
    }
    input.ignore(10000, '"');
    
    input.getline(addr.street, 64, '"');

    if (!input)
    {
        cerr << "Problem reading the address!\n";
        return false;
    }
    else
    {
        address = addr;
        return true;
    }
}


bool readFromBinary(Address& address, ifstream& input)
{
    Address addr;
    assert(input.good());
    input.read((char*)&addr, sizeof(addr));
    bool result = input.good() && input.gcount() == sizeof(addr);
    if (result) address = addr;
    return result;
}


bool printAddressToStream(const Address& address, ostream& output)
{
    assert(output.good());
    output << address.city << ','
        << address.ZIP << ','
        << address.number << ','
        << '"' << address.street << '"'
        << endl;
    return output.good();
}


bool writeToBinary(const Address& address, ofstream& output)
{
    assert(output.good());
    output.write((char*)&address, sizeof(address));
    return output.good();
}


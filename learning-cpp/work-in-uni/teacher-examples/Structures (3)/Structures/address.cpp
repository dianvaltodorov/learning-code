/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)
*  ������ �� ��������� - ��������� �����              */
/******************************************************/


#include <iostream>
#include "address.h"

using std::cin;
using std::cout;
using std::endl;

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


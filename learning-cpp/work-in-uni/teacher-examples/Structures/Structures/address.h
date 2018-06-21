/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)
* ������ �� ��������� - ��������� ����������� �����
* �������� �� ������� �������� ������.
* ������� �� ������ � ��������� �� ����������� �����  */
/******************************************************/


#ifndef _ADDRESS_HEADER_INCLUDED_
#define _ADDRESS_HEADER_INCLUDED_

struct Address
{
    char city[32];
    char street[64];
    unsigned short number;
    unsigned long ZIP;
};

// ������� ������� ����� �� ����������� �����
void printAddress(const Address& address);

// ���� ����� �� ����� �� ����������� ����
void readAddress(Address& address);

#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

// ������� �� ������ / ����� ��� ������� - �������� � �������
bool readAddressFromStream(Address& address, istream& input);
bool readFromBinary(Address& address, ifstream& input);
bool printAddressToStream(const Address& address, ostream& output);
bool writeToBinary(const Address& address, ofstream& output);


#endif //_ADDRESS_HEADER_INCLUDED_

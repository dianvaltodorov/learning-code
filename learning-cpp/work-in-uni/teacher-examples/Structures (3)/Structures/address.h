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

#endif //_ADDRESS_HEADER_INCLUDED_

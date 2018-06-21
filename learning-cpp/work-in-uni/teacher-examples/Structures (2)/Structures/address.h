/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)             */
/******************************************************/


#ifndef _ADDRESS_HEADER_INCLUDED_
#define _ADDRESS_HEADER_INCLUDED_

#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;


namespace fmi{
namespace oop{


class Address
{
public:
    // ������������ � �����������
    // ����������� ��
    Address();
    // ������������
    Address(const char* city, const char* street, unsigned num, unsigned zip);
    // ������� - ���������� ������������ �� default - C++ 11
    Address(const Address& rhs) = default;

    //����������
    ~Address() = default;

    // ������� �� ������ �� ��������
    // ����
    void setCity(const char* city);
    const char* getCity() const { return city; }

    // �����
    void setStreet(const char* street);
    const char* getStreet() const { return street; }

    // �����
    void setNumber(unsigned num);
    unsigned gedNumber() const { return number; }

    // �������� ���
    void setZip(unsigned zip);
    unsigned gedZip() const { return ZIP; }

    // ������� ������� (���� � �����)
    // ������� ������� ����� �� ����������� �����
    void print() const;
    // ���� ����� �� ����� �� ����������� ����
    void read();

private:
    // ������� �� ������ / ����� ��� ������� - �������� � �������
    bool readFromStream(istream& input);
    bool readFromBinary(ifstream& input);
    bool printToStream(ostream& output) const;
    bool writeToBinary(ofstream& output) const;

private:
    char city[32];
    char street[64];
    unsigned short number;
    unsigned long ZIP;
};

} // oop
} // fmi

#endif //_ADDRESS_HEADER_INCLUDED_

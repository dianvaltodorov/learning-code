/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)             */
/******************************************************/


#include <iostream>
#include <fstream>
#include <cassert>
#include "address.h"

namespace fmi{
namespace oop{


using namespace std;

Address::Address()
    : number(0)
    , ZIP(0)
{
    setCity("Unknown");
    setStreet("Unknown");

#ifdef _DEBUG
    cout << " >>>>>> Default ctor of Address called! \n";
#endif
}

Address::Address(const char* city, const char* street, unsigned num, unsigned zip)
{
    setCity(city);
    setStreet(street);
    setNumber(num);
    setZip(zip);

#ifdef _DEBUG
    cout << " >>>>>> ctor with arguments of Address called! \n";
#endif
}


void Address::setCity(const char* city)
{
    city = city ? city : "Somewhere";
    strncpy(this->city, city, sizeof(this->city) - 1);
}


void Address::setStreet(const char* street)
{
    street = street ? street : "unknown street";
    strncpy(this->street, street, sizeof(this->street) - 1);
}


void Address::setNumber(unsigned num)
{
    // ���� ��������� �������� �� ����� ��� ���� ������
    this->number = num;
}


void Address::setZip(unsigned zip)
{
    // ���� ��������� �������� �� ����� ��� ���� ������    
    this->ZIP = zip;
}


void Address::read()
{
    cout << "Enter city: ";
    cin.getline(city, 32);

    if (!cin) // ���������� ������ �� � ���� �������
    {
        cin.clear();
        cin.sync();
    }

    cout << "Enter ZIP code: ";
    cin >> ZIP;
    while (!cin)
    {
        cin.clear();
        cin.sync();
        cout << "You must enter positiv number! \n Enter ZIP code again";
        cin >> ZIP;
    }

    // ��� ������ � � ����� ���������
    cin.sync();
    cout << "Enter street: ";
    cin.getline(street, 64);

    // ��� �� � ���� ����� � �����������, �� ���� �� �� ����������.
    do
    {
        if (!cin)
        {
            cin.clear();
            cin.sync();
        }
        cout << "Enter number: ";
        cin >> number;
    } while (!cin);

    // ������ �� �������� ������ � ����� ��������� � ���������� ������ ��������
    cin.sync();
}


void Address::print() const
{
    cout << "City: " << city << endl;
    cout << "ZIP code: " << ZIP << endl;
    cout << "Street and number: " << number << ", " << street << endl;
}


//////////////////////////////////////
bool Address::readFromStream(istream& input)
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
        *this = addr;
        return true;
    }
}


bool Address::readFromBinary(ifstream& input)
{
    Address addr;
    assert(input.good());
    input.read((char*)&addr, sizeof(addr));
    bool result = input.good() && input.gcount() == sizeof(addr);
    if (result) *this = addr;
    return result;
}


bool Address::printToStream(ostream& output) const
{
    assert(output.good());
    output << city << ','
        << ZIP << ','
        << number << ','
        << '"' << street << '"'
        << endl;
    return output.good();
}


bool Address::writeToBinary(ofstream& output) const
{
    assert(output.good());
    output.write((char*)this, sizeof(Address));
    return output.good();
}

} // oop
} // fmi
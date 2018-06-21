/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)             */
/******************************************************/


#ifndef _STUDENT_HEADER_INCLUDED_
#define _STUDENT_HEADER_INCLUDED_

#include "address.h"
#include <fstream>
using std::fstream;

namespace fmi{
namespace oop{

/* ������ ��� �� ����������� */
enum Programme
{
    PROGRAME_UNKNOWN,      // ��������� / ���������� �����������
    INFORMATICS,           // �����������
    COMPUTER_SCIENCSE,     // ���������� �����
    MATH,                  // ����������
    APPLIED_MATH,          // �������� ����������
    STATICTICS,            // ����������

    PROGRAME_COUNT         // ������ �� ���� �� ��������� ���������
};


class Student
{
public:
// ������������ � �����������
    // ����������� �� �����������
    Student();
    // ������� �����������
    Student(const Student& rhs);
    // ����������� � ���������
    Student(const char* name, const Address& address,
        Programme prg, unsigned fn, unsigned grp, bool regular = true);

    ~Student();

// ������ �� ������
    const char* getName() const { return name; }
    const Address& getAddress() const { return address; }
    Programme getProgramme() const { return program; }
    unsigned getFN() const { return facNum; }
    unsigned getCourse() const { return course; }
    unsigned getGroup() const { return group; }
    unsigned getStream() const { return stream; }
    bool isRegular() const;
    bool isInterrupted() const;

    void setName(const char* name);
    void setAddress(const Address& address);
    void setProgramme(Programme p) { program = p; }
    void setFN(unsigned fn);
    void setGroup(unsigned group);
    void setInterrupted(bool);
    
    void goToNextCourse();

// ����� ������
    // ������� ������� �� ������� ������� �� ����������� �����
    void print() const;

    // ������� �� ����� �� ������� �� ������� � ������� ����
    bool store(fstream& file) const;

    // ������� �� ������ �� ������� �� ������� �� ������� ����
    bool load(fstream& file);

private:
    // ��������� ����������� �� ������ ������ �������������
    bool checkFN(unsigned fn);
    
    // �������� ���������� �������
    void clearData();

// ������� �� ��������
    char* name;                  // ��� - ��������� ������� ���
    Address address;             // ����� - ������� ���������
    Programme program;           // ����������� - ������� ���
    unsigned facNum;             // ���������� �����
    unsigned char course;        // � ��� ���� � � �������
    unsigned char group;         // �����
    unsigned char stream;        // �����
    unsigned char status;        // ������� ��� ������� ��������, ���� � ���������...
};

const unsigned RegularFlag      = (1 << 0);
const unsigned InterruptFlag    = (1 << 1);

} // oop
} // fmi 

#endif //_STUDENT_HEADR_INCLUDED_

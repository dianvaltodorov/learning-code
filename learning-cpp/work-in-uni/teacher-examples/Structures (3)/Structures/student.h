/******************************************************/
/* �������� ��� ��� ����� ���, ��� (2016)
*  ������ �� ��������� - ��������� ����������� �������
* ��� �������: 
*   - ������� ���; 
*   - ������ � ��������� �������� �����;
*   - ������� ���������;
*   - ������ ������.
* ��� ������� �� ���� � �����                         */
/******************************************************/


#ifndef _STUDENT_HEADER_INCLUDED_
#define _STUDENT_HEADER_INCLUDED_

#include "address.h"

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

/* ��������� �������� ������� */
struct Student
{
    char* name;                  // ��� - ��������� ������� ���
    Address address;             // ����� - ������� ���������
    Programme program;           // ����������� - ������� ���
    // ������� ������� �������� ����������� � ������ ������
    unsigned int facNum    : 17; // ���������� �����
    unsigned int course    : 3;  // � ��� ���� � � �������
    unsigned int group     : 4;  // �����
    unsigned int stream    : 2;  // �����
    unsigned int regular   : 1;  // ������� ��� ������� ��������
    unsigned int interrupt : 1;  // ���� � ���������
    unsigned int           : 4;  // ������������
};

// ���� ������� �� ������� �� ����������� ����.
// ������ ������� ������� (�.�. � ������� �������� �� ���)
void readStudent(Student& student);

// ������� ������� �� ������� ������� �� ����������� �����
void printStudent(const Student& student);

// �������� �������, �������� �� ��������.
void clearStudentData(Student& student);

#endif //_STUDENT_HEADER_INCLUDED_

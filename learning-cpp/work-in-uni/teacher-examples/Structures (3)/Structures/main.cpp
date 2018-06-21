#include <iostream>
using std::cout;
using std::endl;

#include "address.h"
#include "student.h"

// ������� ������ �������� �� ������ �����������.
// �������� ����� �� �������� ���� ����� �����.
// ����������� ������ ��� ��������� ��� ���������
void printAllFromProgramme(Programme prg, Student* students, int cnt)
{
    for (Student* iter = students; iter < students + cnt; ++iter)
    {
        if (iter->program == prg)
            printStudent(*iter);
    }
}

int main()
{
    Student students[5];
    for (int i = 0; i < 5; ++i)
    {
        students[i].name = NULL;
        readStudent(students[i]);
    }

    for (int i = 0; i < 5; ++i)
    {
        printStudent(students[i]);
    }

    for (int i = (int)PROGRAME_UNKNOWN; i < (int)PROGRAME_COUNT; ++i)
    {
        cout << "\n\n";
        printAllFromProgramme((Programme)i, students, 5);
    }

    for (int i = 0; i < 5; ++i)
    {
        clearStudentData(students[i]);
    }

    return 0;
}

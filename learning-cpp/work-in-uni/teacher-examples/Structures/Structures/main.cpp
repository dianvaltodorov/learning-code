#include <iostream>
#include <fstream>
using namespace std;


#include "address.h"
#include "student.h"

void generateStudentFile()
{
    Student students[5];

    for (int i = 0; i < 5; ++i)
    {
        students[i].name = NULL;
        readStudent(students[i]);
    }

    fstream file("students.dat", ios::out | ios::binary | ios::trunc);
    if (!file)
    {
        cerr << "Problem with the file...";
        return;
    }
    for (int i = 0; i < 5; ++i)
    {
        if (!store(students[i], file)) 
            break;
    }

    file.close();
}

void printStudentsFromFile()
{
    Student s;
    s.name = NULL;
    fstream file("students.dat", ios::in | ios::binary);

    while (load(s, file))
        printStudent(s);
    file.close();
}

void toUpper(char* text)
{
    while (*text)
    {
        if (*text >= 'a' && *text <= 'z')
        {
            *text = *text - 'a' + 'A';
        }
        ++text;
    }
}

void changeNameOfAllInf()
{
    Student s;
    s.name = NULL;
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    
    if (!file) return;
    streampos begin = 0;
    while (load(s, file))
    {
        if (s.program == INFORMATICS)
        {
            toUpper(s.name);
            streampos end = file.tellg();
            file.seekp(begin, ios::beg);
            store(s, file);
            file.seekg(end, ios::beg);
        }
        begin = file.tellg();
    }
    file.close();
}

int main()
{
//    generateStudentFile();
    printStudentsFromFile();
//    changeNameOfAllInf();
//    printStudentsFromFile();
}

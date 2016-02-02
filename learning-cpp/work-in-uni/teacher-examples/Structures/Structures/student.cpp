/******************************************************/
/* Примерен код към курса ООП, ФМИ (2016)
*  Пример за структури - структура студент            */
/******************************************************/

#include "student.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

using namespace std;

// Декларации на помощни функции
static void readName(char*& name);
static Programme readProgramme();
static unsigned int readNumber(const char* name, unsigned max);
static bool readFlag(const char* name);
static const char* const programeToText(Programme prg);

void readStudent(Student& student)
{
    // Преди да четем нови данни - чистим старите
    clearStudentData(student);

    readName(student.name);
    readAddress(student.address);
    student.program = readProgramme();

    student.facNum = readNumber("faculty number", (1 << 17) - 1); // ограничение до макс. число в типа
    student.course = readNumber("course", 6);      // максимално 5-ти курс
    student.stream = readNumber("stream", 4);      // максимално 3-ти поток
    student.group = readNumber("group", 11);       // максимално 10-та група

    student.regular = readFlag("Is regular student?");
    student.interrupt = readFlag("Is the student interrupt?");
}

void printStudent(const Student& student)
{
    cout << "\n**************************************************************************\n";
    cout << "Information for student " << student.name << endl;
    cout << "Address: " << endl;
    printAddress(student.address);
    cout << "Programme: " << programeToText(student.program) << endl;
    cout << "FN: " << student.facNum << endl;
    cout << "Course: " << student.course << endl;
    cout << "Stream: " << student.stream << endl;
    cout << "Group: " << student.group << endl;
    cout << "The student is " << (student.regular ? "" : "not ") << "regular." << endl;
    cout << "The student is " << (student.interrupt ? "" : "not ") << "interrupted." << endl;
    cout << "**************************************************************************\n";
}

void clearStudentData(Student& student)
{
    delete[] student.name;
}

// Чете данни за името на студента. Грижи се за динамичната памет
static void readName(char*& name)
{
    char buffer[1024];

    cout << "Enter name for the student: ";
    cin.getline(buffer, sizeof(buffer));
    if (!cin)
    {
        cin.clear();
        cin.sync();
    }

    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
}



// Чете данни за специалност
static Programme readProgramme()
{
    Programme prg = PROGRAME_UNKNOWN;
    cout << "Enter programme: ";

    cin >> (int&)prg;
    if (!cin)
        cin.clear();
    if (prg >= PROGRAME_COUNT || prg < PROGRAME_UNKNOWN)
    {
        cout << "Invalid value. The programme must be a number between " << PROGRAME_UNKNOWN
             << " and " << (PROGRAME_COUNT - 1) << endl;
    }
    return prg;
}

// Чете число без знак с ограничение. Подава се и помощен текст
static unsigned int readNumber(const char* name, unsigned max)
{
    unsigned val = max;

    do
    {
        cout << "Enter " << name << ": ";
        cin >> val;
        if (!cin)
        {
            cin.clear();
            cin.ignore();
        }
    } while (val >= max);

    cin.sync();         // Премахваме остатъците в потока
    return val;
}

// Чете булева стойност. Подава се подканващ въпрос.
static bool readFlag(const char* name)
{
    char ans;
    do
    {
        cout << name << "(y/n): ";
        cin >> ans;
    } while (ans != 'n' && ans != 'y' && ans != 'N' &&ans != 'Y');
    cin.sync();
    return ans == 'y' || ans == 'y';
}

static const char* const programeToText(Programme prg)
{
    switch (prg)
    {
    case PROGRAME_UNKNOWN:   return "Unknown program";
    case INFORMATICS:        return "Informatics";
    case COMPUTER_SCIENCSE:  return "Computer sciense";
    case MATH:               return "Math";
    case APPLIED_MATH:       return "Applied math (bow)";
    case STATICTICS:         return "Statistics";
    default:                 return "Bad programme value!";
    }

    // must never reach this line
    assert(false);
    return NULL;
}


/////////////////////////////
bool store(const Student& student, fstream& file)
{
    if (!file) return false;
    
    size_t len = strlen(student.name);
    file.write((char*)&len, sizeof(len));
    if (!file) return false;
    file.write(student.name, len);
    if (!file) return false;
    
    size_t size = sizeof(Student) - sizeof(void*);
    file.write((char*)&student.address, size);
    return file.good();
}


bool load(Student& student, fstream& file)
{
    if (!file) return false;
    size_t size;
    file.read((char*)&size, sizeof(size));
    if (!file) return false;

    delete[] student.name;
    student.name = new char[size + 1];
    streamsize readBytes = 0;
    while (readBytes < size)
    {
        file.read(student.name + readBytes, size - readBytes);
        if (!file) return false;
        readBytes += file.gcount();
    }
    student.name[size] = '\0';

    size_t offset = (size_t)&((Student*)NULL)->address;
    assert(offset == sizeof(void*));

    file.read((char*)&student.address, sizeof(student) - offset);
    return file.good();
}


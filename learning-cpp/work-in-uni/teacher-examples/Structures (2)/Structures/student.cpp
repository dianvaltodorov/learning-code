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

namespace fmi{
namespace oop{

namespace _helpers
{
    // Декларации на помощни функции
    static void readName(char*& name);
    static Programme readProgramme();
    static unsigned int readNumber(const char* name, unsigned max);
    static bool readFlag(const char* name);
    static const char* const programeToText(Programme prg);
}


Student::Student() 
    : name(NULL)
//  , address()
    , program(PROGRAME_UNKNOWN)
    , facNum(0)
    , course(1)
    , group(1)
    , stream(1)
    , status(0)
{
#ifdef _DEBUG
    cout << " >>>>>> Called default ctor for Student \n";
#endif
}

Student::Student(const Student& rhs)
    : name(NULL)
    , address(rhs.address)
    , program(rhs.program)
    , facNum(rhs.facNum)
    , course(rhs.course)
    , group(rhs.group)
    , stream(rhs.stream)
    , status(rhs.status)
{
    setName(rhs.getName());

#ifdef _DEBUG
    cout << " >>>>>> Called copy ctor for Student \n";
#endif
}


Student::Student(const char* name, const Address& address,
    Programme prg, unsigned fn, unsigned grp, bool regular)
    : name(NULL)
    , address(address)
    , status(regular ? RegularFlag : 0)
    , course(1)
{
    setGroup(grp);
    setName(name);
    setProgramme(prg);
    if (checkFN(fn))
    {
        setFN(fn);
    }
    else    // при невалидни данни в конструктора
    {
        clearData();                // зачистваме каквото сме заделили
        throw "Bad fac num!";       // и хвърляме изключение
    }

#ifdef _DEBUG
    cout << " >>>>>> Called argument ctor for Student \n";
#endif
}


Student::~Student()
{
    clearData();

#ifdef _DEBUG
    cout << " <<<<<< Called dtor for Student \n";
#endif
}


bool Student::isRegular() const
{
    return status & RegularFlag;
}


bool Student::isInterrupted() const
{
    return 0 != (status & InterruptFlag);
}


void Student::setName(const char* name)
{
    if (NULL == name)
    {
        throw "Invalid name! Students must have name!";
    }

    delete[] this->name;
    this->name = strcpy(new char[strlen(name) + 1], name);
}


void Student::setAddress(const Address& addres)
{
    this->address = address;
}


void Student::setFN(unsigned fn)
{
    if (!checkFN(fn))
        throw "This FN is invalid for students programme!";
    facNum = fn;
}


void Student::setGroup(unsigned group)
{
    this->group = group;
    stream = (group <= 5) ? 1 : 2;
}


void Student::setInterrupted(bool interrupt)
{
    if (interrupt)
        status |= InterruptFlag;
    else
        status &= ~InterruptFlag;
}


void Student::goToNextCourse()
{
    if (course < 5) ++course;
}


void Student::print() const
{
    using namespace _helpers;

    cout << "\n**************************************************************************\n";
    cout << "Information for student " << getName() << endl;
    cout << "Address: " << endl;
    getAddress().print();
    cout << "Programme: " << programeToText(getProgramme()) << endl;
    cout << "FN: " << getFN() << endl;
    cout << "Course: " << getCourse() << endl;
    cout << "Stream: " << getStream() << endl;
    cout << "Group: " << getGroup() << endl;
    cout << "The student is " << (isRegular() ? "" : "not ") << "regular." << endl;
    cout << "The student is " << (isInterrupted() ? "" : "not ") << "interrupted." << endl;
    cout << "**************************************************************************\n";
}


bool Student::store(fstream& file) const
{
    if (!file) return false;
    
    size_t len = strlen(getName());
    file.write((char*)&len, sizeof(len));
    if (!file) return false;
    file.write(getName(), len);
    if (!file) return false;
    
    size_t size = sizeof(Student) - sizeof(void*);
    file.write((char*)&address, size);
    return file.good();
}


bool Student::load(fstream& file)
{
    if (!file) return false;
    size_t size;
    file.read((char*)&size, sizeof(size));
    if (!file) return false;

    delete[] name;
    name = new char[size + 1];
    streamsize readBytes = 0;
    while (readBytes < size)
    {
        file.read(name + readBytes, size - readBytes);
        if (!file) return false;
        readBytes += file.gcount();
    }
    name[size] = '\0';

    size_t offset = (size_t)&((Student*)NULL)->address;
    assert(offset == sizeof(void*));

    file.read((char*)&address, sizeof(Student) - offset);
    return file.good();
}


void Student::clearData()
{
    delete[] name;
}


bool Student::checkFN(unsigned fn)
{
    assert(program < PROGRAME_COUNT);

    switch (program)
    {
    case PROGRAME_UNKNOWN:      return true;
    case INFORMATICS:           return 4 == fn / 10000;
    case COMPUTER_SCIENCSE:     return 8 == fn / 10000;
    case MATH:                  return 1 == fn / 10000;
    case APPLIED_MATH:          return 3 == fn / 10000;
    case STATICTICS:            return 0 == fn / 10000;
    default: return false;
    }
}


namespace _helpers
{
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

} // _helpers

} // oop
} // fmi
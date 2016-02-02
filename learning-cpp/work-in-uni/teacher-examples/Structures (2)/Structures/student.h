/******************************************************/
/* Примерен код към курса ООП, ФМИ (2016)             */
/******************************************************/


#ifndef _STUDENT_HEADER_INCLUDED_
#define _STUDENT_HEADER_INCLUDED_

#include "address.h"
#include <fstream>
using std::fstream;

namespace fmi{
namespace oop{

/* Избоен тип за специалност */
enum Programme
{
    PROGRAME_UNKNOWN,      // невалидна / неизвестна специалност
    INFORMATICS,           // информатика
    COMPUTER_SCIENCSE,     // компютърни науки
    MATH,                  // математика
    APPLIED_MATH,          // приложна математика
    STATICTICS,            // статистика

    PROGRAME_COUNT         // маркер за край на валидните стойности
};


class Student
{
public:
// Конструктори и деструктори
    // Подразбиращ се конструктор
    Student();
    // Копиращ конструктор
    Student(const Student& rhs);
    // Конструктор с параметри
    Student(const char* name, const Address& address,
        Programme prg, unsigned fn, unsigned grp, bool regular = true);

    ~Student();

// Методи за достъп
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

// Други методи
    // Извежда данните за подаден студент на стандартния изход
    void print() const;

    // Функция за запис на данните за студент в двоичен файл
    bool store(fstream& file) const;

    // Функция за четене на данните за студент от двоичен файл
    bool load(fstream& file);

private:
    // Проверява валидността на номера спрямо специалността
    bool checkFN(unsigned fn);
    
    // изчиства заделените ресурси
    void clearData();

// Данните за студента
    char* name;                  // име - динамично заделен низ
    Address address;             // адрес - вложена структура
    Programme program;           // специалност - изброен тип
    unsigned facNum;             // факултетен номер
    unsigned char course;        // в кой курс е в момента
    unsigned char group;         // група
    unsigned char stream;        // поток
    unsigned char status;        // редовно или задочно обучение, дали е прекъсвал...
};

const unsigned RegularFlag      = (1 << 0);
const unsigned InterruptFlag    = (1 << 1);

} // oop
} // fmi 

#endif //_STUDENT_HEADR_INCLUDED_

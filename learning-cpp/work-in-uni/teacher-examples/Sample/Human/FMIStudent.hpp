#ifndef __FMI_STUDENT_HEADER_INCLUDED_
#define __FMI_STUDENT_HEADER_INCLUDED_

#include "Student.hpp"
#include "Employee.hpp"

class FMIStudent : public Student, public Employee
{
public:
    FMIStudent(const char* name, int fn, double sal)
        : Human(name)
        , Student(fn, "Pesho")
        , Employee(sal, "Gosho")
    {
    }

    virtual void info()const
    {
        cout << "E-e-e-eh, FMI..." << endl;
        Student::info();
        Employee::info();
    }
};

#endif // __FMI_STUDENT_HEADER_INCLUDED_

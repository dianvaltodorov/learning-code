#ifndef __MASTER_HEADER_INCLUDED_
#define __MASTER_HEADER_INCLUDED_

#include "Student.hpp"
#include "Employee.hpp"

class Master : public Student
{
public:
    Master(const char* spec, const char* name, int fn)
        : Human(name)
        , Student(fn, "Pesho")
        , spec(spec)
    {
    }

    virtual void info()const
    {
        cout << "Master at: " << spec << endl;
        Student::info();
    }
protected:
    std::string spec;
};

#endif // __MASTER_HEADER_INCLUDED_

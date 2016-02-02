#ifndef __STUDENT_HEADER_INCLUDED_
#define __STUDENT_HEADER_INCLUDED_

#include "Human.hpp"

class Student : virtual public Human
{
public:
    Student(int fn, const char* name) : Human(name)
    {
        this->fn = fn;
    }

    virtual void info() const
    {
        cout << "FN: " << getFn() << " name: " << getName() << endl;
    }

    int getFn() const
    {
        return fn;
    }

protected:
    int fn;
};

#endif // __STUDENT_HEADER_INCLUDED_

#ifndef __EMPLOYEE_HEADER_INCLUDED_
#define __EMPLOYEE_HEADER_INCLUDED_

#include <math.h>

class Employee : virtual public Human
{
public:
    Employee(double salary, const char* name) : Human(name)
    {
        setSalary(salary);
    }

    void setSalary(double sal)
    {
        salary = fabs(sal);
    }

    double getSalary() const
    {
        return salary;
    }

    virtual void info() const
    {
        cout << "I'm " << getName() << " and my salary is " << getSalary() << endl;
    }

protected:
    double salary;
};

#endif // __EMPLOYEE_HEADER_INCLUDED_

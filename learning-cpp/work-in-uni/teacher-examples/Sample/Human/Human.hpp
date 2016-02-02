#ifndef __HUMAN_HEADER_INCLUDED_
#define __HUMAN_HEADER_INCLUDED_

#include <iostream>
using std::cout;
using std::endl;

#include <string>

class Human
{
public:
    Human(const char* name) : name(name)
    {}

    virtual ~Human()
    {}

    const char* getName()const
    {
        return name.c_str();
    }

    void setName(const char* name)
    {
        this->name = name;
    }

    virtual void info() const
    {
        cout << name << endl;
    }
private:
    string name;
};

#endif // __HUMAN_HEADER_INCLUDED_

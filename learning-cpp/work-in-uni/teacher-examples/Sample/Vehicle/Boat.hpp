#ifndef __BOAT_HEADER_INCLUDED_
#define __BOAT_HEADER_INCLUDED_

#include <string>
#include "Vehicle.hpp"

class Boat : public Vehicle
{
public:
    Boat(const char* name, unsigned maxSpeed) : Vehicle(maxSpeed)
    {
        setName(name);
    }

    virtual void print() const
    {
        cout << "I'm " << getName() << "  "
             << "My max speed is " << getSpeed() << endl;
    }

    void setName(const char* name)
    {
        this->name = name;
    }

    const char* getName() const
    {
        return name.c_str();
    }

private:
    std::string name;
};

#endif // __BOAT_HEADER_INCLUDED_

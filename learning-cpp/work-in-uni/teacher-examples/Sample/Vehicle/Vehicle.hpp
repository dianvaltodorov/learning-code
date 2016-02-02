#ifndef __VEHICLE_HEADER_INCLUDED_
#define __VEHICLE_HEADER_INCLUDED_

#include <iostream>
using std::cout;
using std::endl;

class Vehicle
{
public:
    Vehicle(unsigned maxSpeed):speed(0)
    {
        setSpeed(maxSpeed);
    }

    virtual ~Vehicle(){}

    unsigned getSpeed() const
    {
        return speed;
    }

    virtual void print() const
    {
        cout << "Vehicle. Max speed: " << getSpeed() << endl;
    }

    void setSpeed(unsigned speed)
    {
        if (speed >= 0)
        {
            this->speed = speed;
        }
    }

protected:
    unsigned speed;
};

#endif // __VEHICLE_HEADER_INCLUDED_

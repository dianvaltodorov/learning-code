#ifndef __PLANE_HEADER_INCLUDED_
#define __PLANE_HEADER_INCLUDED_

#include "Vehicle.hpp"

class Plane : public Vehicle
{
public:
    Plane(unsigned height, unsigned maxSpeed) : Vehicle(maxSpeed)
    {
        setHeight(height);
    }

    virtual void print() const
    {
        cout << "I can fly up to " << getHeight() << " and with "
             << getSpeed() << " km/h" << endl;
    }

    unsigned getHeight() const
    {
        return height;
    }

    void setHeight(unsigned height)
    {
        if (height >= 0)
        {
            this->height = height;
        }
    }

private:
    unsigned int height;
};

#endif // __PLANE_HEADER_INCLUDED_

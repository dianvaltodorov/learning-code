#ifndef __HYDROPLANE_HEADER_INCLUDED_
#define __HYDROPLANE_HEADER_INCLUDED_

#include "Boat.hpp"
#include "Plane.hpp"

class Hydroplane : public Boat, public Plane
{
public:
    Hydroplane(int regNum)
      : Boat("St. Louise", 60)
      , Plane(3000, 350)
      , regNum(regNum)
    {
    }

    virtual void print() const
    {
        cout << "Hydroplane " << regNum << endl;
        Boat::print();
        Plane::print();
    }

    int getRegNum() const
    {
        return regNum;
    }

protected:
    const int regNum;
};

#endif //__HYDROPLANE_HEADER_INCLUDED_

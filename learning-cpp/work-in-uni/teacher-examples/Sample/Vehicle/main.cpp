#include <iostream>
using namespace std;

#include "Hydroplane.hpp"

int main()
{
    Hydroplane h1(1234);
    Plane* pl = new Hydroplane(1111);
    Vehicle* v = pl;


    pl->print();
    v->print();
    cout << "--------------- \n";
    h1.print();
    h1.Boat::setSpeed(100);
    h1.Plane::setSpeed(1000);
    h1.print();
    cout << "--------------- \n";
    return 0;
}

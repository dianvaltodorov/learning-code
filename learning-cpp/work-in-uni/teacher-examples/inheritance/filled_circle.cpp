/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2016
*/

#include "filled_circle.hpp"

#include <iostream>
using std::cout;
using std::endl;


FilledCircle::FilledCircle(const Point& center, int r, const string& color)
    : Circle(center, r)
    , color (color)
{
}

void FilledCircle::print() const
{
    cout << "Filled circle: ";
    Circle::print();
    cout << color << endl;
}

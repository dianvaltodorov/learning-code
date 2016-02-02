/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2016
*/

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_circle.hpp"

#include <iostream>

using namespace std;

void print(const Shape& s)
{
    s.print();
    cout << "Area: " << s.getArea();
    cout << endl;
}

void printCircle(const Circle& c)
{
    c.print();
    cout << "Area: " << c.getArea();
    cout << endl;
}

int main()
{
    Point zero;
    Point point(3, 5);
    cout << "Shape test: " << endl;

    Shape unknown;
    unknown.print();
    unknown.moveWith(point);
    unknown.print();

    cout << "\n\nCircle test: " << endl;
    Circle c(zero, 3);
    print(c);
    printCircle(c);

    cout << "\n\nFilled Circle test: " << endl;
    FilledCircle fc(point, 5, "Black");
    printCircle(fc);
    fc.print();

    return 0;
}

/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2016
*/

#include "shape.hpp"

#include <iostream>
using std::cout;
using std::endl;


Shape::Shape()
{
    //cout << "Shape created!" << endl;
}

void Shape::moveWith(const Point& vec)
{
    // Използваме знанията за преместане описани в класа за точка.
    TL.moveWith(vec);
    BR.moveWith(vec);
}

double Shape::getArea() const
{
    // Няма как да пресметнем лицето на базова (обща) фигура.
    // Затова изписваме някаква информация и връщаме 0.
    // Скоро ще видим как ще се справим с тази особеност ;)
    cout << "Calculating the ares - it is unknown..." << endl;
    return 0.0;
}

void Shape:: print() const
{
    cout << "Top left point: " << TL << endl;
    cout << "Bottom right point: " << BR << endl;
}


Point Shape::getTopLeft() const
{
    return TL;
}

void Shape::setTopLeft(const Point& point)
{
    TL = point;
    swapIfNeeded();
}

Point Shape::getBtmRight() const
{
    return BR;
}

void Shape::setBtmRight(const Point& point)
{
    BR = point;
    swapIfNeeded();
}

// Подреждаме точките, ако е нужно.
// Приемаме, че работим със стандартна, положителна координатна сиситема.
void Shape::swapIfNeeded()
{
    if (TL.getX() > BR.getX())
    {
        int x = TL.getX();
        TL.setX(BR.getX());
        BR.setX(x);
    }

    if (TL.getY() < BR.getY())
    {
        int y = TL.getY();
        TL.setY(BR.getY());
        BR.setY(y);
    }
}

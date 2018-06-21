/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
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
    // ���������� �������� �� ���������� ������� � ����� �� �����.
    TL.moveWith(vec);
    BR.moveWith(vec);
}

double Shape::getArea() const
{
    // ���� ��� �� ���������� ������ �� ������ (����) ������.
    // ������ ��������� ������� ���������� � ������� 0.
    // ����� �� ����� ��� �� �� ������� � ���� ��������� ;)
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

// ���������� �������, ��� � �����.
// ��������, �� ������� ��� ����������, ����������� ����������� ��������.
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

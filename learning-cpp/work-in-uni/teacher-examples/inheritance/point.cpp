/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#include "point.hpp"

#include <iostream>
using std::cout;
using std::endl;

Point::Point(int x, int y)
{
    setX(x);
    setY(y);
}

int  Point::getX() const
{
    return x;
}

int  Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::moveWith(const Point & vec)
{
    x += vec.x;
    y += vec.y;
}

void Point::moveTo(const Point & vec)
{
    x = vec.x;
    y = vec.y;
}

ostream& operator << (ostream& os, const Point& p)
{
    os << '(' << p.getX() << ", " << p.getY() << ')';
    return os;
}

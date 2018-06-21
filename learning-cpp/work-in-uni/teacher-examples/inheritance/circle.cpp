/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#include "circle.hpp"

#include <iostream>
using std::cout;
using std::endl;


Circle::Circle(const Point& center, int r)
    : center(center)
{
    if (r <= 0) throw "Incorrect value for radius";

    resize(r);
}

Point Circle::getCenter() const
{
    return center;
}

void Circle::moveTo(const Point& point)
{
    Point moveVector(point.getX() - center.getX(), point.getY() - center.getY());
    moveWith(moveVector);

    center = point;
}

void Circle::resize(unsigned int radius)
{
    if (radius > 0)
    {
        this->radius = radius;
        setTopLeft(Point(center.getX() - (radius+1)/2, center.getY() + (radius+1)/2));
        setBtmRight(Point(center.getX() + (radius+1)/2, center.getY() - (radius+1)/2));
    }
}

double Circle::getArea()const
{
    return radius*radius*3.1415;
}

void Circle::print() const
{
    cout << "Info for a circle: " << endl;
    // ���������� �� ����� ����� � ������������� �� � ����������
    Shape::print();
    cout << "Center: " << center << endl;
    cout << "Radius: " << radius << endl;
}

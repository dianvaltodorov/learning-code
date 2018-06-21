/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#include "rectangle.hpp"

#include <iostream>
using std::cout;
using std::endl;


Rectangle::Rectangle(const Point& topLeft, int width, int height)
// � ����� �������� � ��-����� � ��������� ����������� �� ������� �����
// : Rectangle(topLeft, Point(topLeft.getX() + width, topLeft.getY() - height))
{
    setTopLeft(topLeft);
    setBtmRight(Point(topLeft.getX() + width, topLeft.getY() - height));
}

Rectangle::Rectangle(const Point& topLeft, const Point& btmRight)
{
    setTopLeft(topLeft);
    setBtmRight(btmRight);
}

void Rectangle::moveTo(const Point& topLeft)
{
    Point moveVector(topLeft.getX() - getTopLeft().getX(), topLeft.getY() - getTopLeft().getY());
    moveWith(moveVector);
}

void Rectangle::setWidth(unsigned int width)
{
    int diff = width - getWidth();
    setBtmRight(Point(getBtmRight().getX() + diff, getBtmRight().getY()));
}

int Rectangle::getWidth() const
{
    return getBtmRight().getX() - getTopLeft().getX();
}

void Rectangle::setHeight(unsigned int height)
{
    int diff = height - getHeight();
    setBtmRight(Point(getBtmRight().getX(), getBtmRight().getY() + diff));
}

int Rectangle::getHeight() const
{
    return getTopLeft().getY() - getBtmRight().getY();
}

double Rectangle::getArea()const
{
    return getWidth()*getHeight();
}

void Rectangle::print() const
{
    cout << "Info for a rectangle: " << endl;
    Shape::print();
    cout << "Width: " << getWidth() << "; ";
    cout << "Height: " << getHeight() << endl;
}

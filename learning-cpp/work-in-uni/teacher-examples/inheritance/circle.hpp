/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#ifndef __CIRCLE_HEADER_INCLUDED_
#define __CIRCLE_HEADER_INCLUDED_

#include "point.hpp"
#include "shape.hpp"

// ���������. �� � ���� ����� - ��������� Shape
// �������� (�������� �����) Point
class Circle : public Shape
{
public:
    Circle(const Point& center, int r);

    // ���������� �� ����������� ������
    Point getCenter() const;
    void resize(unsigned int radius);   // ������� ������� �� �����������

    // ��������� ������������� �� �������� ��������� �� Shape
    void moveTo(const Point& center);
    double getArea() const;
    void print() const;

private:
    Point center;
    int radius;
};

#endif // __CIRCLE_HEADER_INCLUDED_

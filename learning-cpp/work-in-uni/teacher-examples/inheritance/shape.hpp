/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#ifndef __SHAPE_HEADER_INCLUDED_
#define __SHAPE_HEADER_INCLUDED_

#include "point.hpp"

// ����� ���� ������� ���������� ������.
// �������� (��������) �����
class Shape
{
public:
    Shape();

    // ���� ������ �� ������ �����
    void moveWith(const Point& vec);    // ����������
    double getArea() const;             // ��������� ������
    void print() const;                 // ������� ���������� �� ��������

protected:
    // ������ ���������� ������������ � ���������� �����
    // �� ���������� �������� ������ �� ������.
    Point getTopLeft() const;
    void setTopLeft(const Point&);

    Point getBtmRight() const;
    void setBtmRight(const Point&);

private:
    // ������� ����� �� �������� �� ���������� ������������.
    // �������� �� ���� ������� �� ����� �� ������������ ��.
    void swapIfNeeded();

private:
    // ���������� �� ���������� ������������
    // ������ ����������� ������� �� ������� �� ������
    Point TL, BR;
};

#endif // __SHAPE_HEADER_INCLUDED_

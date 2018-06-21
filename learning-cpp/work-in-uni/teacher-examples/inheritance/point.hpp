/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#ifndef __POINT_HEADER_INCLUDED_
#define __POINT_HEADER_INCLUDED_

// ������� ���� �����. �������� �� �� �������� �� ������ ����������, ����� � ������ � 2D
class Point
{
public:
    // ����������� � ��������� �� ������������
    Point(int x = 0, int y = 0);

    // ������ �� ������ �� ������������
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    // ��� ������ �� ������� �� ������� �� �����
    void moveWith(const Point & vec);   // ����������
    void moveTo(const Point & point);   // �����������

private:
    // �� �������� �� ������ ����������� ����������
    int x, y;
};

#include <iostream>
using std::ostream;
ostream& operator << (ostream& os, const Point& p);

#endif // __POINT_HEADER_INCLUDED_

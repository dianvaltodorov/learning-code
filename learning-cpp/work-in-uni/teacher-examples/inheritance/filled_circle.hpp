/* �������� ��� �� ������������ �� ����������� � ����������;
   ������ � ���������� �������.
 ���, ��� 2016
*/

#ifndef __FILLED_CIRCLE_HEADER_INCLUDED_
#define __FILLED_CIRCLE_HEADER_INCLUDED_

#include "circle.hpp"
#include <string>
using std::string;

// ��-����� ��� ��������� - ��������� � ��� ���������.
// �� � ���� ��������� - ��������� Circle
class FilledCircle : public Circle
{
public:
    FilledCircle(const Point& center, int r, const string& color = "white");

    // ����������� ���������� ������ �� ��������� �� ����������
    void print() const;

private:
    // ��� ���������� ����� �� ����
    string color;
};

#endif // __FILLED_CIRCLE_HEADER_INCLUDED_

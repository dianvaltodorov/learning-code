/* �������� ��� �� ������������ �� �������� ������� �� ����
 ���, ��� 2016
*/


#ifndef __OBJECT_COUNTER_HEADER_INCLUDED_
#define __OBJECT_COUNTER_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// ������ �� ����, ������ ���� �� ������ ������
// ����� ����� ��� ���� ���� �������� �������������.
class ObjectCounter
{
public:
    // ���� ������, ���� � �������.
    static int getCurrentCount();

public:
    // ����������� �� � ������� �����������. �������� ���� ���� ������.
    // ������� �������� �������������
    ObjectCounter();
    ObjectCounter(const ObjectCounter&);

    // ���������� - �������� ���� ���� ������
    ~ObjectCounter();

    // ��� ����������� ������ �� ��������� ���������� ID
    ObjectCounter& operator=(const ObjectCounter& rhs);

    int getObjID() const;

private:
    static int count;
    static int nextID;

private:
    int id;

private:
    // ������� ������� �� ���������� �� �������� ID �� �����
    static int getNextID();
};

}// oop
}// fmi

#endif // __OBJECT_COUNTER_HEADER_INCLUDED_


/* �������� ��� �� ������������ �� �������� ������� �� ����.
 ������ ��� (singleton)
 ���, ��� 2016
*/


#ifndef __SINGLETON_HEADER_INCLUDED_
#define __SINGLETON_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// ������ �� ����, �� ����� ��� ���������� ���������
// ����� ����� ��� ���� ���� �������� �������������.
class Singleton
{
public:
    // �������� �����, ���� ����� �� �������� ������������ ���������
    static Singleton& getInstance();

public:
    // ������� ��������, ����� �������� ����� �� ��������
    void print() const;

private:
    // ����������� ����������� ������
    Singleton();                    // ��� � �� �� ����� �������� ���������
    Singleton(const Singleton&);    // ���� �� �������������� ��������� �����������
    void operator=(const Singleton&);   // ���� � ��������� =. ���������� �������� ���.
    ~Singleton();                   // ��������� �� ����������� �� ��������� �� delete
};

}//oop
}//fmi

#endif //__SINGLETON_HEADER_INCLUDED_

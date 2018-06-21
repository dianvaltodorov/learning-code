/* �������� ��� �� ������������ �� �������� ������� �� ����.
 ������ � ��������� (resource pool)
 ���, ��� 2016
*/

#ifndef __WORKER_HEADER_INCLUDED_
#define __WORKER_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// ����, ���������� ����������� ������� - ���������.
class Worker
{
friend class ObjectPool;
public:
    void dig() const;

private:
    // ���� ������������ ���� �� ��� ������ �� ���� ������.
    Worker(int num);
    ~Worker();

    int getNum()const {return num;}

    // ���� �� ����� ��������������
    Worker(const Worker&);
    void operator=(const Worker&);

private:
    int num;
    bool isHired;
};

} // oop
} // fmi

#endif //__WORKER_HEADER_INCLUDED_

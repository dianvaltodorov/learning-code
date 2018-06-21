/* �������� ��� �� ������������ �� �������� ������� �� ����.
 ������ � ��������� (resource pool)
 ���, ��� 2016
*/

#ifndef __OBJECT_POOL_HEADER_INCLUDED_
#define __OBJECT_POOL_HEADER_INCLUDED_

#include "worker.hpp"

namespace fmi{
namespace oop{

// ����, ���������� ������� � ���������.
// ������ ��� � ���������.
// ���������� ��������� ���� ������ �� Worker, ��������� ��� ����� �����.
class ObjectPool
{

public:
    // ���������� ���� ���������
    static const unsigned maxWorkers = 5;

public:
    // ����� ������������ ��������� �� ����
    static ObjectPool& getPool();

public:
    // ����� �������� �������� �� ������� ��� ������ ����������
    Worker& hireWorker();

    // ����������� ���� ��������.
    void dismissWorker(Worker& w);

private:
    ObjectPool(unsigned numWorkers);
    ~ObjectPool();

    ObjectPool(const ObjectPool&);
    void operator=(const ObjectPool&);

private:
    unsigned numWorkers;        // ��� ���� ���������
    unsigned numFree;           // ���� �������� ���������
    Worker** pool;              // ������ � �����������
    bool* isDigging;            // ������ ��� �� �������� � ��� �������
};

} // oop
} // fmi

#endif //__OBJECT_POOL_HEADER_INCLUDED_

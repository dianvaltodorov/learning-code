/* �������� ��� �� ������������ �� �������� ������� �� ����.
 ������ � ��������� (resource pool)
 ���, ��� 2016
*/

#include "objPool.hpp"
#include <cassert>
#include <iostream>

namespace fmi{
namespace oop{

ObjectPool& ObjectPool::getPool()
{
    static ObjectPool thePool(maxWorkers);
    return thePool;
}

ObjectPool::ObjectPool(unsigned num)
{
    numWorkers = num;
    pool = new Worker* [num];
    isDigging = new bool[num];

    for (numFree = 0; numFree < num; ++numFree)
    {
        pool[numFree] = NULL;
        isDigging[numFree] = false;
    }
}

ObjectPool::~ObjectPool()
{
    for (unsigned i = 0; i < numWorkers; ++i)
        delete pool[i];
    delete[] pool;
    delete[] isDigging;
}


Worker& ObjectPool::hireWorker()
{
    // � ������, �� ���� ������ �������� ���������
    if (!numFree)
    {
        throw "No free workers!\n";
    }

    for (unsigned i = 0; i < numWorkers; ++i)
    {
        // ������ ������, ����� �� � ����
        if (!isDigging[i])
        {
            if (!pool[i])   // ��� ��� �� � �������� �� ���������
            {
                pool[i] = new Worker(i);
            }
            // �����������, �� ����� ����
            --numFree;
            isDigging[i] = true;
            assert(!pool[i]->isHired);
            pool[i]->isHired = true;

            // � ������� ��������� �� �������
            return *pool[i];
        }
    }

    // ������ �� ������ �� ������� ���� ���...
    assert(false);
}

void ObjectPool::dismissWorker(Worker& w)
{
    // �������� �� ���������
    assert (w.getNum() >= 0 && w.getNum() < numWorkers);
    if (!isDigging[w.getNum()])
    {
        throw "Worker already dismissed!\n";
    }

    assert(w.isHired);

    // ����������� ��������� ���� ��������.
    w.isHired = false;
    isDigging[w.getNum()] = false;
    ++numFree;
}

} // oop
} // fmi

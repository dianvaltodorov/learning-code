/* Примерен код за демонстрация на статични членове на клас.
 Басейн с работници (resource pool)
 ФМИ, ООП 2016
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
    // В случай, че няма повече свободни работници
    if (!numFree)
    {
        throw "No free workers!\n";
    }

    for (unsigned i = 0; i < numWorkers; ++i)
    {
        // Търсим първия, който не е зает
        if (!isDigging[i])
        {
            if (!pool[i])   // Ако още не е създаден го създаваме
            {
                pool[i] = new Worker(i);
            }
            // Отеблязваме, че имаме нает
            --numFree;
            isDigging[i] = true;
            assert(!pool[i]->isHired);
            pool[i]->isHired = true;

            // И връщаме псевдоним на клиента
            return *pool[i];
        }
    }

    // Никога не трябва да стигнем този ред...
    assert(false);
}

void ObjectPool::dismissWorker(Worker& w)
{
    // Проверки за валидност
    assert (w.getNum() >= 0 && w.getNum() < numWorkers);
    if (!isDigging[w.getNum()])
    {
        throw "Worker already dismissed!\n";
    }

    assert(w.isHired);

    // Отбелязваме работника като свободен.
    w.isHired = false;
    isDigging[w.getNum()] = false;
    ++numFree;
}

} // oop
} // fmi

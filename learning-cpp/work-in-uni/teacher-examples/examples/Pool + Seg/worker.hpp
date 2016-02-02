/* Примерен код за демонстрация на статични членове на клас.
 Басейн с работници (resource pool)
 ФМИ, ООП 2016
*/

#ifndef __WORKER_HEADER_INCLUDED_
#define __WORKER_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// Клас, представящ специалните ресурси - работници.
class Worker
{
friend class ObjectPool;
public:
    void dig() const;

private:
    // Само приятелският клас ще има достъп до тези методи.
    Worker(int num);
    ~Worker();

    int getNum()const {return num;}

    // Няма да бъдат имплементирани
    Worker(const Worker&);
    void operator=(const Worker&);

private:
    int num;
    bool isHired;
};

} // oop
} // fmi

#endif //__WORKER_HEADER_INCLUDED_

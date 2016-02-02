/* Примерен код за демонстрация на статични членове на клас.
 Басейн с работници (resource pool)
 ФМИ, ООП 2016
*/


#include <iostream>
#include "worker.hpp"

namespace fmi{
namespace oop{

void Worker::dig() const
{
    if (!isHired)
    {
        std::cout << "No! " << std::endl;
    }
    else
    {
        std::cout << "I'm " << num
                  << " and I will dig for you, Master! " << std::endl;
    }
}

Worker::Worker(int num) : num(num), isHired(false)
{
    std::cout << "Worker " << num << " created." << std::endl;
}

Worker::~Worker()
{
    std::cout << "Worker " << num << " destroyed." << std::endl;
}


} // oop
} // fmi

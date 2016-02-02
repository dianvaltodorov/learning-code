/* Примерен код за демонстрация на статични членове на клас
 ФМИ, ООП 2016
*/

#include "ObjectCounter.hpp"

namespace fmi{
namespace oop{

//Инициализиране на статичните членове
int ObjectCounter::count = 0;
int ObjectCounter::nextID = 0;

int ObjectCounter::getCurrentCount()
{
    return count;
}

ObjectCounter::ObjectCounter()
{
    ++count;
    this->id = ObjectCounter::getNextID();
}

ObjectCounter::ObjectCounter(const ObjectCounter& rhs)
{
    ++count;
    this->id = ObjectCounter::getNextID();
}

ObjectCounter::~ObjectCounter()
{
    --count;
}

ObjectCounter& ObjectCounter::operator=(const ObjectCounter& rhs)
{
    // Нищо в левия обект не се променя - пазим ID-то.
    // Ако имаше други данни трябваше да копираме тях.
    return *this;
}

int ObjectCounter::getObjID() const
{
    return id;
}

int ObjectCounter::getNextID()
{
    return nextID++;
}

}// oop
}// fmi

/* Примерен код за демонстрация на статични членове на клас.
 Шаблон сег (singleton)
 ФМИ, ООП 2016
*/
#include <iostream>
#include "Singleton.hpp"

using std::cout;
using std::endl;

namespace fmi{
namespace oop{


Singleton& Singleton::getInstance()
{
    static Singleton theInstance;
    return theInstance;
}

void Singleton::print() const
{
    cout << "Hello design patterns! " << endl;
}

Singleton::Singleton()
{
    cout << "The instance is created!" << endl;
}

Singleton::~Singleton()
{
    cout << "The instance is destroyed!" << endl;
}

} // oop
} // fmi

/* Примерен код за демонстрация на статични членове на клас
 ФМИ, ООП 2016
*/


#ifndef __OBJECT_COUNTER_HEADER_INCLUDED_
#define __OBJECT_COUNTER_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// Пример за клас, следящ броя на живите обекти
// Всеки обект има също свой уникален идентификатор.
class ObjectCounter
{
public:
    // Брой обейти, живи в момента.
    static int getCurrentCount();

public:
    // Подразбиращ се и копиращ конструктор. Променят броя живи обекти.
    // Задават уникален идентификатор
    ObjectCounter();
    ObjectCounter(const ObjectCounter&);

    // Деструктор - намалява броя живи обекти
    ~ObjectCounter();

    // При присвояване трябва да запазваме уникалното ID
    ObjectCounter& operator=(const ObjectCounter& rhs);

    int getObjID() const;

private:
    static int count;
    static int nextID;

private:
    int id;

private:
    // Помощна функция за пресмятане на следващо ID на обект
    static int getNextID();
};

}// oop
}// fmi

#endif // __OBJECT_COUNTER_HEADER_INCLUDED_


/* Примерен код за демонстрация на статични членове на клас.
 Шаблон сег (singleton)
 ФМИ, ООП 2016
*/


#ifndef __SINGLETON_HEADER_INCLUDED_
#define __SINGLETON_HEADER_INCLUDED_

namespace fmi{
namespace oop{

// Пример за клас, от който има единствена инстанция
// Всеки обект има също свой уникален идентификатор.
class Singleton
{
public:
    // Статичен метод, през който се достъпва единствената инстанция
    static Singleton& getInstance();

public:
    // Някакво действие, което очакваме класа да извършва
    void print() const;

private:
    // Забраняваме специалните методи
    Singleton();                    // Ако е са ни нужни добавяме параметри
    Singleton(const Singleton&);    // НЯМА да имплементираме копиращия конструктор
    void operator=(const Singleton&);   // също и оператора =. Забележете връщания тип.
    ~Singleton();                   // Забраната на деструктора ни предпазва от delete
};

}//oop
}//fmi

#endif //__SINGLETON_HEADER_INCLUDED_

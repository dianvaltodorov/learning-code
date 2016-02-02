/* Примерен код за демонстрация на наследяване и наслояване;
   бавози и производни класове.
 ФМИ, ООП 2016
*/

#ifndef __FILLED_CIRCLE_HEADER_INCLUDED_
#define __FILLED_CIRCLE_HEADER_INCLUDED_

#include "circle.hpp"
#include <string>
using std::string;

// По-широк вид окръжност - Запълнена с фон окръжност.
// Тя Е СЪЩО окръжност - наследява Circle
class FilledCircle : public Circle
{
public:
    FilledCircle(const Point& center, int r, const string& color = "white");

    // Предефинира единствено метода за извеждане на информация
    void print() const;

private:
    // Има специфични данни за цвят
    string color;
};

#endif // __FILLED_CIRCLE_HEADER_INCLUDED_

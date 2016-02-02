```
#include <cassert.h>
class Rational
{
  public:
  void setNom(int);
  void setDenom(int);

  int getNome()
  {
    return this->nom;
  }

  int getNome()
  {
    return this->deonom;
  }

  pricate:
    int nom;
    int denom;
};

void  Rational::setNom(int nom)
{
  this->nom = nom;
}

void Rational::setDenom(int denom)
{
  this->denom = denom;
}

void Rational::setDenom(int denom)
{

}
int main()
{
  Rational r = {1, 2};
  //cout << r.nom << "/" << e.denom << endl;
  //r.denom = 0; // никой не може да ме спре да правя така.

  std::cout << r.getDenom() << "/" << r.getDenom() << endl;
}

```

Спецификатори за достъп.
* private - достъпно само в рамките на функцията
* protected - достъпно за по ниските нива
* public - по подразбиране

Искаме да можем да попитаме колко ти е числителя и колко ти е  знаменателя.

Типът на указателя е константен указател. Тогава типът му е (Rational*const)
Вътрешно се дефинира един указател, който сочи към самия обект, който сме изготвили

this->denom;

r.denom();

Подразбиращ се конструктор.
Конструктор е функция, която се извиква за да се създаде обект. Вика се точно веднъж и после вече не се вика.
Може ада имаме няколко public секции, които смислово да групират член данни и члун функции. Но не е добра идея да имаме редуване на спецификатори за достъп.
std::Rational - оператор за принадлежност


```
const Rational (1,2);
r.getNom() - компилаторът си мисли, че няма да го променя

int getNom() const // с това тържествено обещавам, че няма да правя промени по обекта. Всички функции, които го ползва за четене
{

}
```

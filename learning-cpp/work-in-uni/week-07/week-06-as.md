* процедурно програмиране - активна част(процедури) и данни
* ооп - отделни модулче, комплектовани данни и операции. Програмата не е функции, а има множество обекти, които си комуникират и правят някакви работи.
* разликата между клас и структура - при структурата по подразбиране всичко е public. На 90% са взаимно взаменяеми. Структурата е пасивно
* съставни типове - състоят се от множество опаковане в коплект
* атомарни типове - int, char, double
* идеята е структурата да си остане на ниво само комплект на данни без да се дават функции.
* Така не се знае се съдържа в теци pointer-и. Няма как да се укаже дали е валидно създаден обекта. Ако бяхме в процедурния свят, си правим отделна функция, която е белува.

```
class Person
{
  public:
    char* pszFirstName;
    char* pszLastName;
    char szEGN [11];
}

bool allocateAndCopy(char * target, const char * value)
{
  if(!value)
    return false; // в случай, че стойността, която трябва да се копира е NULL

  try
  {
    target = new char[strlen(value) + 1];
  } catch(std::bad_alloc& e)
  {
    return false;
  }

  strcpy(target, value);
  return true;
}

void init(Person& obj,
          const char * pszFirstName,
          const char * pszLastName,
          const char * szEGN,
          int Age)
{
  allocateAndCopy(obj,pszFirstName, pszFirstName);
  allocateAndCopy(obj,pszLastName, pszFirstName);
  allocateAndCopy(obj,pszFirstName, pszFirstName);
  obj.age = age;
}
int main()
{
  Person obj;
  obj.pszFirstName = new char[strlen("Ivan") + 1];
  strcpy(obj.firstName, "Ivan");

  obj.pszLastName = new char[strlen("Ivanov") + 1];
  strcpy(obj.lastName, "Ivanov");

  obj.age = rand();

  allocateAndCopy(p, NULL);
  allocateAndCopy(p, "dido");

  //============================
  init(obj1, "Ivan", "Ivanov", "12345", rand());
  init(obj1, "", "", "", 0);
  return 0;
}
```
* ако трябва да се тества такава функция, се прави
* Унгарска конвенция

```
psz = p
string
c string
psz
```
* идеята е като се създаде обекта, той да е във валидно състояние.
* при процедурното има проблем с това, че трябва да се вика функция, която валидира състоянието на обекта.
* при ооп се въвежда концепцията за контструктори наместо на init
* може да имаме множеството конструктори.

```
class Person
{
  private:
    char* pszFirstName;
    char* pszLastName;
    char szEGN [11];
  public:
    Person();
    Person(const cahr*,const cahr*,const cahr*,const cahr*);
    ~Person();
}

Person::~Person()
{
  delete [] pszFirstName;
  delete [] pszLastName;
}

Person::Person(const char * pszFirstName,
               const char * pszLastName,
               const char * szEGN,
               int Age)
{
  allocateAndCopy(this->pszFirstName, pszFirstName);
  allocateAndCopy(this->pszLastName, pszFirstName);
  allocateAndCopy(this->szEGN, szEGN);
  obj.age = age;
}

int main()
{
  Person obj1("Ivan", "Ivanov", "12345", radn());
  Person obj1;

  int x = offset(Person, pszFirstName);
  x = offset(Person, pszLastName);

}
```
* деструкторът е написат
* всичките обекти се държат по еднакъв начин. създават се със конструктор и се унищожават чрез деструктора.
* delete върху NULL не прави нищо
* straosout, uisit, scot meyers, manik
* books:
  - Scott Meyers
    - Effective C++
    - More Effective C++
    - Effective Modern C++
  - Straostrup
    -C++
    -C++ FAQ
  - Josuttis
    - The C++ Standard Library
```
  new  Person();
  f()
  {
     static int x = compute(); // heavy computing;
     x = 6;
     x = 3
  }

  g()
  {

  }
```
* статичните обекти, не им се подава this pointer
* C++11 е все едно C++ 2=0
```
4B - указтел
4B - указател
4B - указател
11B + 1B - масив към байтове, от един от байтовете
4
```

* Вътрешното подравняване е едно
* стековото подравняване е друго.
* ако имаме структура, в която имам 2 байта
* правилотое е ако почнем с големите променливи и малките ще спечелим най много място.
* идеята е, че те са на 64 бита
* подравнява се най-голямото
* началото + сто
* взима малки, поне на толкова на колкото ги гълта
* проблемът е когато е едно нещо е разнесено между две. Всичките трябва да влизат в една клетка
* една прочина всички да са кратни на 2, това е много удобно.
* два short-a влизат в long long
* блокчета от по четири и имаме нещо от по три байта,
* защо е паметта е 4 GBл С колко бита се адресират няколко други работи.
* locality

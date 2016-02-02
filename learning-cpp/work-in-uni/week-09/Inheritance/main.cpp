#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;

class Person
{
private:
    int Age;
    char* pName;
private:
    Person(Person const&){}
    Person& operator=(Person const &) {}
public:
    Person();
    ~Person();
public:
    int GetAge() const;
    void SetAge(int);
    const char * GetName() const;
    void SetName(const char * NewName);
protected:
    AllocateString(pValue, NewName);
};

void AllocateString(
        char*& ptr,
        const char *pValue)
{

}


void Person::SetName(const char * NewName)
{
    char *pBuffer;
    try
    {
        // присовяването е следното. Първо се изчислява дясното. Ако то хвърил exception,няма да се присвои.
        pBuffer = new char[strlen(NewName) + 1];
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Cannot allocate memory!\n";
        return;
    }
    delete[] pName;
    pName = pBuffer;
}

void Person::SetName(const char * NewName)
{
    char *pBuffer;
    try
    {
        // присовяването е следното. Първо се изчислява дясното. Ако то хвърил exception,няма да се присвои.
        pBuffer = new char[strlen(NewName) + 1];
    }
    catch(std::bad_alloc& e)
    {
        std::cerr << "Cannot allocate memory!\n";
        return;
    }
    delete[] pName;
    pName = pBuffer;
}




Person::Person()
{
    Age = 0;
    pName = NULL;
}

Person::~Person()
{
   delete [] pName;
}


// Така наследяваме всички методи, но всички са public. Това
class Worker : public Person
{

};

// Така наследяваме всички методи, но всички са private
class Worker : private Person
{
public:
    int GetAge() const
    {
        return -5;
    }

    void f()
    {
        GetAge();
    }
};

int main()
{
    Person obj1;
    obj1.SetAge(5);
    obj1.SetName("Ivan");
    cout << obj1.GetName() << endl;

    Student s;

    Worker w;
    w.SetAge(50);
    w.SetName("chubaka");
    w.Person::SetAge(50);
    w.Worker::SetAge(60);
    return 0;
}

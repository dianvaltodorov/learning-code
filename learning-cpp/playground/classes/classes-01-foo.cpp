#include <iostream>

class Foo
{
public:
    /** Default constructor */
    Foo() :
        data (new char[14])
    {
        std::strcpy(data, "Hello, World!");
    }

    /** Copy constructor */
    Foo (const Foo& other) :
        data (new char[std::strlen (other.data) + 1])
    {
        std::strcpy(data, other.data);
    }


    /** Destructor */
    ~Foo() /* explicitly specified destructors should be annotated noexcept as best-practice */
    {
        delete[] data;
    }

    /** Copy assignment operator */
    Foo& operator= (const Foo& other)
    {
        Foo tmp(other);         // re-use copy-constructor
        *this = std::move(tmp); // re-use move-assignment
        return *this;
    }

private:
    friend std::ostream& operator<< (std::ostream& os, const Foo& foo)
    {
        os << foo.data;
        return os;
    }

    char* data;
};
 
int main()
{
    const Foo foo;
    std::cout << foo << std::endl;

    return 0;
}

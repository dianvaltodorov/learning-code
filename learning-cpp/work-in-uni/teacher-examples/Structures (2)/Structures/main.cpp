#include <iostream>
#include <fstream>
using namespace std;


#include "address.h"
#include "student.h"

using namespace fmi::oop;


Student test()
{
    Address adr;
    Student sb("John Doe", adr, INFORMATICS, 43123, 1);
    return sb;
}

void print(Student s)
{
    cout << "Printing data ....";
    s.print();
}

int main()
{
    Student pesho;
    pesho.setName("Pesho");
    pesho.print();

    Address adr("Sofia", "Studentski", 52, 1700);
    Student gosho("Gosho", adr, INFORMATICS, 43000, 3, true);
    gosho.print();
    Student nasko = gosho;
    print(test());

    try
    {
        Student badGuy("WD", adr, INFORMATICS, 1000, 1);
    }
    catch (const char* what)
    {
        cout << "Bad guy catched : "
            << what << endl;
    }
    return 0;
}

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    /*
    char a[32];
    char b[10];
    cin.getline(a, 6);
    cin.getline(b, 10);
    cout << "Print the content of a and b: "
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << cin << endl;
    */

    cout << "entre a string. The length should be between 0 and 4. If it is bigger the fail is risen." << endl;
    char c[10];
    cin.getline(c, 5);
    cout << c << endl;
    cout << cin << endl;
    cout << "cin.good() = " << cin.good() << endl;
    cout << "cin.bad() = " << cin.bad() << endl;
    cout << "cin.eof() = " << cin.eof() << endl;
    cout << "cin.fail() = " << cin.fail() << endl;
    if(!cin)
    {
      cin.clear();
      cin.sync();
      cin.get(); // изтрива последния прочетен нов ред
    }
    cin.ignore(INT_MAX);
    char b[10];
    cin.getline(b, 10);
    cout << b << endl;
    return 0;
}

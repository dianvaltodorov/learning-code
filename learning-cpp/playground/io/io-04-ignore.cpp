#include <iostream>
using namespace std;
int main()
{
  char x;
  cin.get(x);
  cout << "x = " << x << endl;
  cout << "cin = " << cin << endl;
  cin.ignore(4);
  char y;
  cin.get(y);
  cout << "y = " << y << endl;
  cout << "cin = " << cin << endl;
}
